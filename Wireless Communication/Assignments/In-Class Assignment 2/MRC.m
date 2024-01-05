clc;
clear all;
close all;

SNR_in_dB = 0 : 1 : 30;
SNR = 10 .^ (SNR_in_dB / 10);
BER_1 = zeros([1, length(SNR_in_dB)]);
BER_2 = zeros([1, length(SNR_in_dB)]);
BER_3 = zeros([1, length(SNR_in_dB)]);

len = 1e5;
data = randi(2, 1, 2 * len) - 1;
data = cat(1, data(1 : len), data(len + 1 : 2 * len));

E_b = 1;
sym = E_b * (1 - 2 * data) / sqrt(2);
mapped_symbols = complex(sym(1, : ), sym(2, : ));

h11 = abs(randn([1, len]) + 1i * randn([1, len])) / sqrt(2);
h12 = abs(randn([1, len]) + 1i * randn([1, len])) / sqrt(2);
h13 = abs(randn([1, len]) + 1i * randn([1, len])) / sqrt(2);
h1_norm = abs(h11) .^ 2 + abs(h12) .^ 2 + abs(h13) .^ 2;

m = 0.5;
nakagami_pdf = makedist('Nakagami','mu',m,'omega',1);
h21 = random(nakagami_pdf, 1, len) .* exp(2i * pi * rand(1, len));
h22 = random(nakagami_pdf, 1, len) .* exp(2i * pi * rand(1, len));
h23 = random(nakagami_pdf, 1, len) .* exp(2i * pi * rand(1, len));
h2_norm = abs(h21) .^ 2 + abs(h22) .^ 2;

for i = 1 : length(SNR_in_dB)
    
    mean = complex(0, 0);
    sigma = 1 / sqrt(2 * SNR(i));
    noise = mean + sigma * complex(randn([1, len]), randn([1, len]));
    
    y11 = h11 .* mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y12 = h12 .* mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y13 = h13 .* mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    
    y21 = h21 .* mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y22 = h22 .* mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y23 = h23 .* mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    
    y31 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y32 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    y33 = mapped_symbols + complex_gaussian_noise(complex(0, 0), SNR(i), len);
    
    y1 = (conj(h11) .* y11 + conj(h12) .* y12 + conj(h13) .* y13) ./ h1_norm;
    y2 = (conj(h21) .* y21 + conj(h22) .* y22 + conj(h23) .* y23) ./ h2_norm;
    y3 = (y31 + y32 + y33) / 3;
    
    BER_1(i) = calculateBER(data, y1);
    BER_2(i) = calculateBER(data, y2);
    BER_3(i) = calculateBER(data, y3);
end

semilogy(SNR_in_dB, BER_1, 'b.-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_2, 'r.-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_3, 'g.-', 'linewidth', 1);
hold off;

legend('Rayleigh', 'AWGN', 'Nakagami-m', 'Location', 'northeast');
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