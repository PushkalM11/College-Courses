clc; clear; close all;

rng(4, 'philox'); % For reproducibility

format long;

%% This is start point to record time elapsed
tic

%% SNR declaration
SNR_in_dB = 2 : 1 : 20;
SNR = 10 .^ (SNR_in_dB / 10);

%% Generating binary data for all 3 users
% Note that the data is in frequency domain

N = 64;
N2 = 2 * N;

N_monte_carlo= 1000;

M = 2; %BPSK

data_1 = randi(2, 1, N) - 1;
data_2 = randi(2, 1, N) - 1;
data_3 = randi(2, 1, N) - 1;

% BPSK modulation
E_b = 1;

symbols_1 = real(pskmod(data_1, M));
symbols_2 = real(pskmod(data_2, M));
symbols_3 = real(pskmod(data_3, M));

%% Taking IFFT for signals
% User 2 and User 3 have same channel conditions

% Allocating wide subcarriers to user 1 and user 3
ifft_sym_1 = ifft(symbols_1, N);
ifft_sym_3 = ifft(symbols_3, N);

% Allocating narrow subcarriers to user 2
padded_sym_2 = interpolateSignal(symbols_2);
ifft_sym_2 = ifft(padded_sym_2, N2);

%% Power allocation to the users
% User 1 - alpha1
% User 2 - beta2
% User 3 - alpha3
alpha1 = 0.13;
beta2 = 0.34;
alpha3 = 0.53;
P = 1; % Power at base station

%% NOMA at transmitter (downlink scenario)
x_transmitted = zeros(1, N2);
x_transmitted(1 : N) = sqrt(alpha1 * P) * ifft_sym_1;
x_transmitted(N + 1 : N2) = sqrt(alpha3 * P) * ifft_sym_3;
x_transmitted = x_transmitted + (sqrt(beta2 * P) * ifft_sym_2);

% Adding cyclic prefix to symbols
l_cp = 0.25 * N2;
len_x_cp = N2 + l_cp;
x_cp_transmitted = [x_transmitted((N2 - l_cp + 1) : N2), x_transmitted];

%% Distances of users from base station
d1 = 100;
d2 = 1000; d3 = 1000;
% Path loss component
eta = 4;

% Generating rayleigh fading coefficients for all users
g1 = sqrt(d1 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo))/sqrt(2);
g2 = sqrt(d2 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo))/sqrt(2);
g3 = sqrt(d3 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo))/sqrt(2);

h1 = abs(g1);
h2 = abs(g2);
h3 = abs(g3);

%% BER Calculation
ber_1 = zeros(1, length(SNR));
ber_2 = zeros(1, length(SNR));
ber_3 = zeros(1, length(SNR));

for i=1: length(SNR)

    ber_1_temp = 0;
    ber_2_temp = 0;
    ber_3_temp = 0;

    for jj = 1 : N_monte_carlo

        % Signal received at User 1
        y1 = awgn(h1(jj).* x_cp_transmitted, SNR(i),'measured');
        % Signal received at User 2
        y2 = awgn(h2(jj) .* x_cp_transmitted, SNR(i),'measured');
        % Signal received at User 3
        y3 = awgn(h3(jj) .* x_cp_transmitted, SNR(i),'measured');

        % Equalisation at receivers
        r_eq_1 = y1 ./ h1(jj);
        r_eq_2 = y2 ./ h2(jj);
        r_eq_3 = y3 ./ h3(jj);

        % CP removed received signal
        r_eq_1 = r_eq_1(l_cp + 1 : end);
        r_eq_2 = r_eq_2(l_cp + 1 : end);
        r_eq_3 = r_eq_3(l_cp + 1 : end);

        % FFT operation at User 1 and User 3
        fft_r_1_tmp = fft(r_eq_1);
        fft_r_2_tmp = fft(r_eq_2);
        fft_r_3_tmp = fft(r_eq_3);

        % Combining two halves of signal (refer to eq 13) %%%%%%%%%%%%%%%%
        %%%%%%%%%%%%%%%%%%%%%% NEEDS DEBUGGING
        
        fft_r_1= function_Recover_Even_Subcarriers(fft_r_1_tmp);
        fft_r_3= function_Recover_Even_Subcarriers(fft_r_3_tmp);
        fft_r_2= function_Recover_Odd_Subcarriers(fft_r_2_tmp);


        % At User 3 -------------------------------
        % Direct decoding as higher power allocated
        x_3_hat= pskdemod(fft_r_3, M);
        ber_3_temp= ber_3_temp+ calculateBER(data_3, x_3_hat);

        % At User 1 ----------------------------
        % Decode User 3 signal first then remove
        x_3_at_1 = pskdemod(fft_r_1, M);
        x_3_at_1= real(pskmod(x_3_at_1, M)); %Re-modulation of user 3's data
        y_1 = fft_r_1 - (sqrt(alpha3 * P) * x_3_at_1);
        x_1_hat = pskdemod(y_1, M);
        ber_1_temp= ber_1_temp+ calculateBER(data_1, x_1_hat);

        % At User 2 ----------------------------
        % Decode User 1 and User 3 signals
        % Then subtract from equalized signal
        x_3_at_2 = pskdemod(fft_r_2, M);
        x_3_at_2= real(pskmod(x_3_at_2, M));

        y_1_at_2 = fft_r_2 - (sqrt(alpha3 * P) * x_3_at_2);
        x_1_at_2 = pskdemod(y_1_at_2, M);
        x_1_at_2= real(pskmod(x_1_at_2, M));
        
        x_1_3_combined = zeros(1, N2);
        x_1_3_combined(1 : N) = sqrt(alpha1 * P) * x_1_at_2;
        x_1_3_combined(N + 1 : N2) = sqrt(alpha3 * P) * x_3_at_2;

        y_2_hat= fft_r_2 - ((sqrt(alpha1 * P) * x_1_at_2) + sqrt(alpha3 * P) * x_3_at_2);
        x_2_hat = pskdemod(y_2_hat, M);
        ber_2_temp= ber_2_temp+ calculateBER(data_2, x_2_hat);

    end

    ber_1(i)= ber_1_temp/N_monte_carlo;
    ber_2(i)= ber_2_temp/N_monte_carlo;
    ber_3(i)= ber_3_temp/N_monte_carlo;
end

%% Plotting

SNR_BER= figure;
semilogy(SNR_in_dB, ber_1, 'b.-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, ber_2, 'r.-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, ber_3, 'g.-', 'linewidth', 1);
hold off;

legend('User 1', 'User 2', 'User 3', 'Location', 'northeast');
xlabel('SNR in dB');
ylabel('BER');
grid on;
savefig(SNR_BER, "figure_SNR_vs_BER")

%% This is end point to record time elapsed
toc
