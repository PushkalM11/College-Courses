clc; clear; close all;

rng(4, 'philox'); % For reproducibility

format long;

%%
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
data_4 = randi(2, 1, N) - 1;

% BPSK modulation
E_b = 1;

symbols_1 = real(pskmod(data_1, M));
symbols_2 = real(pskmod(data_2, M));
symbols_3 = real(pskmod(data_3, M));
symbols_4 = real(pskmod(data_4, M));

%% Taking IFFT for signals
% User 3 and User 4 have same channel conditions

% Allocating one narrow subcarrier to user 1 and user 4
ifft_sym_1 = ifft(symbols_1, N);
ifft_sym_4 = ifft(symbols_4, N);

% Allocating narrow subcarriers to user 2 and user 3
padded_sym_2 = interpolateSignal_Odd(symbols_2);
padded_sym_3 = interpolateSignal_Odd(symbols_3);

%% Power allocation to the users
% User 1 - alpha1
% User 2 - beta2
% User 3 - beta3
% User 4 - alpha4
alpha1 = 0.1;
beta2 = 0.18;
beta3 = 0.34;
alpha4 = 0.38;
P = 10; % Power at base station

P_1 = sqrt(alpha1 * P);
P_2 = sqrt(beta2 * P);
% P_2 = 0;
P_3 = sqrt(beta3 * P);
P_4 = sqrt(alpha4 * P);

%% NOMA at transmitter (downlink scenario)
x_transmitted = zeros(1, N2);
x_transmitted(1 : N) = P_1 * ifft_sym_1;
x_transmitted(N + 1 : N2) = P_4 * ifft_sym_4;
x_transmitted = x_transmitted + ifft(((P_2 .* padded_sym_2) + (P_3 .* padded_sym_3)));

% Adding cyclic prefix to symbols
l_cp = 0.25 * N2;
len_x_cp = N2 + l_cp;
x_cp_transmitted = [x_transmitted((N2 - l_cp + 1) : N2), x_transmitted];

%% Distances of users from base station
d1 = 100;
d2 = 500; 
d3 = 1000; d4 = 1000;

% Path loss component
eta = 4;

% Generating rayleigh fading coefficients for all users
g1 = sqrt(d1 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo)) / sqrt(2);
g2 = sqrt(d2 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo)) / sqrt(2);
g3 = sqrt(d3 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo)) / sqrt(2);
g4 = sqrt(d4 ^ -eta) * (randn(1, N_monte_carlo) + 1i * randn(1, N_monte_carlo)) / sqrt(2);

h1 = abs(g1);  % returns complex magnitude
h2 = abs(g2);  % for rayleigh distribution
h3 = abs(g3);
h4 = abs(g4);

%% BER Calculation
ber_1 = zeros(1, length(SNR));
ber_2 = zeros(1, length(SNR));
ber_3 = zeros(1, length(SNR));
ber_4 = zeros(1, length(SNR));

for i = 1: length(SNR)

    ber_1_temp = 0;
    ber_2_temp = 0;
    ber_3_temp = 0;
    ber_4_temp = 0;

    for jj = 1 : N_monte_carlo

        % Signal received at User 1  adds awgn
        y1 = awgn(h1(jj) .* x_cp_transmitted, SNR(i),'measured'); 
        % Signal received at User 2
        y2 = awgn(h2(jj) .* x_cp_transmitted, SNR(i),'measured');
        % Signal received at User 3
        y3 = awgn(h3(jj) .* x_cp_transmitted, SNR(i),'measured');
        % Signal received at User 3
        y4 = awgn(h4(jj) .* x_cp_transmitted, SNR(i),'measured');

        % Equalisation at receivers
        r_eq_1 = y1 ./ h1(jj);
        r_eq_2 = y2 ./ h2(jj);
        r_eq_3 = y3 ./ h3(jj);
        r_eq_4 = y4 ./ h4(jj);
        
        % CP removed received signal
        r_eq_1 = r_eq_1(l_cp + 1 : end);
        r_eq_2 = r_eq_2(l_cp + 1 : end);
        r_eq_3 = r_eq_3(l_cp + 1 : end);
        r_eq_4 = r_eq_4(l_cp + 1 : end);

        % FFT operation at User 1 and User 3
        fft_r_1_tmp = fft(r_eq_1);
        fft_r_2_tmp = fft(r_eq_2);
        fft_r_3_tmp = fft(r_eq_3);
        fft_r_4_tmp = fft(r_eq_4);
    
        fft_r_1 = recoverWide_Four(fft_r_1_tmp);
        fft_r_4 = recoverWide_Four(fft_r_4_tmp);
        fft_r_2 = recoverNarrow_Four(fft_r_2_tmp);
        fft_r_3 = recoverNarrow_Four(fft_r_3_tmp);
        
        % At User 4 -------------------------------
        % Direct decoding as higher power allocated
        x_4_hat= pskdemod(fft_r_4, M);
        ber_4_temp= ber_4_temp + calculateBER(data_4, x_4_hat);
        
        % At User 1 -------------------------------
        % Decoding User 4's signal first then removing it
        x_4_at_1 = pskdemod(fft_r_1, M);
        x_4_at_1= real(pskmod(x_4_at_1, M));
        y_1 = fft_r_1 - (P_4 * x_4_at_1);
        x_1_hat = pskdemod(y_1, M);
        ber_1_temp = ber_1_temp + calculateBER(data_1, x_1_hat);
        
        % At User 3 -------------------------------
        % Decoding User 4 and User 1 signal first then removing it
        x_4_at_3 = pskdemod(fft_r_3, M);
        x_4_at_3 = real(pskmod(x_4_at_3, M));

        y_1_at_3 = fft_r_3 - (P_4 * x_4_at_3);
        x_1_at_3 = pskdemod(y_1_at_3, M);
        x_1_at_3= real(pskmod(x_1_at_3, M));
        
        y_3_hat= fft_r_3 - (P_4 * x_4_at_3 + P_1 * x_1_at_3);
        x_3_hat = pskdemod(y_3_hat, M);
        ber_3_temp = ber_3_temp + calculateBER(data_3, x_3_hat);
        
        % At User 2 -------------------------------
        % Decoding User 4, User 1 and User 2 signal first then removing it
        x_4_at_2 = pskdemod(fft_r_2, M);
        x_4_at_2 = real(pskmod(x_4_at_2, M));

        y_1_at_2 = fft_r_2 - (P_4 * x_4_at_2);
        x_1_at_2 = pskdemod(y_1_at_2, M);
        x_1_at_2= real(pskmod(x_1_at_2, M));
        
        y_3_at_2 = fft_r_2 - (P_4 * x_4_at_2 + P_1 * x_1_at_2);
        x_3_at_2 = pskdemod(y_3_hat, M);
        
        y_2_hat = y_3_at_2 - (P_3 * x_3_at_2);
        x_2_hat = pskdemod(y_2_hat, M);
        ber_2_temp = ber_2_temp + calculateBER(data_2, x_2_hat);
        
    end
    
    ber_1(i) = ber_1_temp / N_monte_carlo;
    ber_2(i) = ber_2_temp / N_monte_carlo;
    ber_3(i) = ber_3_temp / N_monte_carlo;
    ber_4(i) = ber_4_temp / N_monte_carlo;
end

%% Plotting

SNR_BER = figure;
semilogy(SNR_in_dB, ber_1, 'b.-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, ber_2, 'c*-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, ber_3, 'ro-', 'linewidth', 1);
hold on;
semilogy(SNR_in_dB, ber_4, 'gs-', 'linewidth', 1);
hold off;

legend('User 1', 'User 2', 'User 3', 'User 4', 'Location', 'northeast');
xlabel('SNR in dB');
ylabel('BER');
grid on;
savefig(SNR_BER, "figure_SNR_vs_BER")

%% This is end point to record time elapsed

toc