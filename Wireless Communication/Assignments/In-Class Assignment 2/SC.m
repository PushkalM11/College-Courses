clc;
clear all;
close all;

format long;

SNR_in_dB = 0 : 1 : 30;
SNR = 10 .^ (SNR_in_dB / 10);

BER_1 = zeros([1, length(SNR_in_dB)]);
BER_2 = zeros([1, length(SNR_in_dB)]);
BER_3 = zeros([1, length(SNR_in_dB)]);
BER_4 = zeros([1, length(SNR_in_dB)]);
BER_5 = zeros([1, length(SNR_in_dB)]);

len = 1e5;
data = randi(2, 1, 2 * len) - 1;
data = cat(1, data(1 : len), data(len + 1 : 2 * len));

E_b = 1;
sym = E_b * (1 - 2 * data) / sqrt(2);
mapped_symbols = complex(sym(1, : ), sym(2, : ));

for i = 1 : length(SNR_in_dB)
    
    h11 = (randn([1, len]) + 1i * randn([1, len])) / sqrt(2); 
    h12 = (randn([1, len]) + 1i * randn([1, len])) / sqrt(2);

    m = 0.5;
    nakagami_pdf = makedist('Nakagami', 'mu', m, 'omega', 1);
    h21 = random(nakagami_pdf, 1, len) .* exp(2i * pi * rand(1, len));
    h22 = random(nakagami_pdf, 1, len) .* exp(2i * pi * rand(1, len));
    
    h1_max = max(abs(h11), abs(h12));
    h2_max = max(abs(h21), abs(h22));
    
    y1 = ((h1_max .* (sqrt(SNR(i)) * mapped_symbols)) + complex_gaussian_noise(complex(0, 0), SNR(i), len)) ./ h1_max;
    y2 = ((h2_max .* (sqrt(SNR(i)) * mapped_symbols)) + complex_gaussian_noise(complex(0, 0), SNR(i), len)) ./ h2_max;
    y3 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y4 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y5 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y6 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    
    BER_1(i) = calculateBER(data, y1);
    BER_2(i) = calculateBER(data, y2);
    BER_3(i) = calculateBER(data, (y3 + y4) / 2);
    BER_4(i) = calculateBER(data, (y3 + y4 + y5) / 3);
    BER_5(i) = calculateBER(data, (y3 + y4 + y5 + y6) / 4);
    
end

semilogy(SNR_in_dB, BER_1, 'ro-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_2, 'go-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_3, 'bo-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_4, 'ko-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_5, 'yo-', 'linewidth', 1);
hold off;

legend('Rayleigh', 'Nakagami-m', 'AWGN - 2 receivers', 'AWGN - 3 receivers', 'AWGN - 4 receivers', 'Location', 'northeast');
xlabel('SNR in dB')
ylabel('BER')
title('BER vs SNR plots for different channels using QPSK modulation')
grid on;

function [BER] = calculateBER(transmitted_bits, received_symbols)
    N = length(received_symbols);
    received_bits = zeros([2, N]);
    for j = 1 : N
        if (real(received_symbols(j)) >= 0) && (imag(received_symbols(j)) > 0)
            b1 = 0;
            b2 = 0;
        elseif (real(received_symbols(j)) >= 0) && (imag(received_symbols(j)) <= 0)
            b1 = 0;
            b2 = 1;
        elseif (real(received_symbols(j)) < 0) && (imag(received_symbols(j)) <= 0)
            b1 = 1;
            b2 = 1;
        else
            b1 = 1;
            b2 = 0;
        end
        received_bits(1, j) = b1;
        received_bits(2, j) = b2;
    end    
    BER = sum(sum(abs(received_bits - transmitted_bits))) / (2 * N);
end

function noise = complex_gaussian_noise(mean, SNR, len)

    sigma = 1 / sqrt(2 * SNR);
    noise = mean + sigma * complex(randn([1, len]), randn([1, len]));

end