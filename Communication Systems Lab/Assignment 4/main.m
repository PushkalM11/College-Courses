clc;
clear all;
close all;

format long;

Na = 100;
number_of_blocks = 1e4;
SNR_in_dB = 0 : 1 : 10;
SNR = 10 .^ (SNR_in_dB / 10);

[BPSK_BER_sim, BPSK_SER_sim] = BPSK(Na, number_of_blocks, SNR_in_dB);
[QPSK_BER_sim, QPSK_SER_sim] = QPSK(Na, number_of_blocks, SNR_in_dB);

BPSK_BER_theoretical = qfunc(sqrt(2 * SNR));
QPSK_SER_theoretical = 2 * qfunc(sqrt(2 * SNR));

semilogy(SNR_in_dB, BPSK_BER_sim, SNR_in_dB, BPSK_SER_sim, "-o", SNR_in_dB, QPSK_BER_sim, SNR_in_dB, QPSK_SER_sim, "square", SNR_in_dB, BPSK_BER_theoretical, '--', SNR_in_dB, QPSK_SER_theoretical, '-.');
grid on;
xlabel('SNR (in dB)', 'FontSize', 14);
ylabel('Error Rates', 'FontSize', 14);
title('Error Rates vs SNR for BPSK and QPSK', 'FontSize', 18);
legend("BER of BPSK", "SER of BPSK", "BER of QPSK", "SER of QPSK", "Theoretical BER & SER of BPSK and BER of QPSK", "Theoretical SER of QPSK", 'FontSize', 12);

function [BER, SER] = BPSK(Na, number_of_blocks, SNR_in_dB)
    BER = zeros(1, length(SNR_in_dB));
    SER = zeros(1, length(SNR_in_dB));
    SNR = 10 .^ (SNR_in_dB / 10);
    Eb = 1;
    symbol_list = [-1 * sqrt(Eb), sqrt(Eb)];    
    for block = 1 : number_of_blocks
        input_bits = randi(2, 1, Na) - 1;
        input_symbols = sqrt(Eb) * (1 - 2 * input_bits);
        for i = 1 : length(SNR_in_dB)
            AWGN_mean = 0;
            AWGN_sigma = 1 / sqrt(2 * SNR(i));
            noise = AWGN_mean + AWGN_sigma * randn([1, Na]);
            received_symbols = input_symbols + noise;
            [detected_symbols, ~] = ML_detector(received_symbols, symbol_list);
            detected_bits = 0.5 * (1 - (detected_symbols / sqrt(Eb)));
            number_of_bit_errors = sum(abs(detected_bits - input_bits));
            BER(i) = BER(i) + (number_of_bit_errors / Na);
            SER(i) = SER(i) + (number_of_bit_errors / Na);
        end
    end
    BER = BER / number_of_blocks;
    SER = SER / number_of_blocks;
end

function [BER, SER] = QPSK(Na, number_of_blocks, SNR_in_dB)
    BER = zeros(1, length(SNR_in_dB));
    SER = zeros(1, length(SNR_in_dB));
    SNR = 10 .^ (SNR_in_dB / 10);
    Eb = 2;
    symbol_list = sqrt(Eb / 2) .* [complex(1, 1), complex(1, -1), complex(-1, 1), complex(-1, -1)];
    for block = 1 : number_of_blocks
        input_bits = randi(2, 1, Na) - 1;
        input_symbols = zeros(1, Na / 2);
        for i = 1 : Na / 2
            b1 = input_bits(2 * i - 1);
            b2 = input_bits(2 * i);
            input_symbols(i) = sqrt(Eb / 2) * complex((1 - 2 * b1), (1 - 2 * b2));
        end
        for i = 1 : length(SNR_in_dB)
            AWGN_mean = complex(0, 0);
            AWGN_sigma = 1 / sqrt(2 * SNR(i));
            noise = AWGN_mean + AWGN_sigma * complex(randn([1, Na / 2]), randn([1, Na / 2]));
            received_symbols = input_symbols + noise;
            [~, detected_index] = ML_detector(received_symbols, symbol_list);
            detected_bits = zeros(1, Na);
            for j = 1 : Na / 2
                if detected_index(j) == 1
                    detected_bits(2 * j - 1) = 0;
                    detected_bits(2 * j) = 0;
                elseif detected_index(j) == 2
                    detected_bits(2 * j - 1) = 0;
                    detected_bits(2 * j) = 1;
                elseif detected_index(j) == 3
                    detected_bits(2 * j - 1) = 1;
                    detected_bits(2 * j) = 0;
                else
                    detected_bits(2 * j - 1) = 1;
                    detected_bits(2 * j) = 1;
                end
            end
            number_of_bit_errors = sum(abs(detected_bits - input_bits));
            BER(i) = BER(i) + (number_of_bit_errors / Na);
            SER(i) = SER(i) + 2 * (number_of_bit_errors / Na);
        end
    end
    BER = BER / number_of_blocks;
    SER = SER / number_of_blocks;
end

function [detected_symbols, detected_index] = ML_detector(received_symbols, symbol_list)
    Na = length(received_symbols);
    detected_symbols = zeros(1, Na);
    detected_index = zeros(1, Na);
    for i = 1 : Na
        [~, index] = min(abs(symbol_list - received_symbols(i)));
        detected_symbols(i) = symbol_list(index);
        detected_index(i) = index;
    end
end