clc;
clear all;
close all;

% Step - 1
M = 2;
N = 64;
        
SNR_in_dB = 0 : 1 : 30;
SNR = 10 .^ (SNR_in_dB / 10); 

tap_power = [0.3, 0.8, 0.2];

BER_1 = calculate_BER_OFDM(SNR, 10000, M, N, 1, 4, tap_power);
BER_2 = calculate_BER_OFDM(SNR, 10000, M, N, 1, 2, tap_power);

figure;
semilogy(SNR_in_dB, BER_1, 'bo-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_2, 'ro-', 'linewidth', 1);
hold off;

legend('CP = 4', 'CP = 2');
xlabel('SNR in dB');
ylabel('BER');
title('Figure 1 : BER vs SNR for OFDM with 3 taps for Broad Band channel');
grid on;

BER_3 = calculate_BER_OFDM(SNR, 10000, M, N, 1, 4, [1]);
BER_4 = calculate_BER_OFDM(SNR, 10000, M, N, 1, 2, [1]);

figure;
semilogy(SNR_in_dB, BER_3, 'bo-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, BER_4, 'ro-', 'linewidth', 1);
hold off;

legend('CP = 4', 'CP = 2');
xlabel('SNR in dB');
ylabel('BER');
title('Figure 2 : BER vs SNR for OFDM with 3 taps for Narrow Band channel');
grid on;

function [BER] = calculate_BER_OFDM(SNR, repetitions, M, N, E_b, L, tap_power)
    
    len = N * log2(M);
    BER = zeros(1, length(SNR));
    for i_snr = 1 : length(SNR)
    
        bit_errs = 0;

        for rep = 1 : repetitions
            % Step - 2
            data = randi(2, 1, len) - 1;

            % Step - 3
            symbols = sqrt(E_b) * (1 - 2 * data);

            % Step - 4
            ifft_symbols = ifft(symbols);

            % Step - 5
            cyclic_prefix = [ifft_symbols(len - L + 1 : len), ifft_symbols];
            len_cyclic_prefix = length(cyclic_prefix);

            % Step - 6
            n_taps = length(tap_power);
            h = sqrt(tap_power) .* (randn(1, n_taps) + 1j * randn(1, n_taps));

            % Step - 7
            noisy_signal = cyclic_prefix + (1 /  sqrt(SNR(i_snr))) * (randn(1, len_cyclic_prefix) + 1j * randn(1, len_cyclic_prefix));
            received = conv(noisy_signal, h);

            % Step - 8
            removed_cp = received( : , L + 1 : end);
            removed_cp = removed_cp(1 : len);

            % Step - 9
            fft_removed_cp = fft(removed_cp);

            % Step - 10
            fft_h = fft(h, len);
            received_eq = fft_removed_cp ./ fft_h;
            predicted_bits = zeros(1, len);
            for i = 1 : len

                if received_eq(i) >= 0

                    predicted_bits(i) = 0;

                else 

                    predicted_bits(i) = 1;

                end

            end
            bit_errors = sum(abs(data - predicted_bits));
            bit_errs = bit_errs + bit_errors;
        end
        BER(i_snr) = bit_errs / (repetitions * len);
    end

end