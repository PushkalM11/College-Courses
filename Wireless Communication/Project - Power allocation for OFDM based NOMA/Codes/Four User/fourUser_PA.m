%% Primary operations
clc;
% clear all;
close all;

rng(4, 'philox'); % For reproducibility

format long;

%% To record time
tic

%% Generating data for users

N = 64;
N2 = 2 * N;
N3 = 3 * N;

l_cp = 0.25 * N2;
M = 2;

N_monte_carlo = 1000;

data_1 = randi(2, 1, N) - 1;
data_2 = randi(2, 1, N) - 1;
% data_2 = zeros(1, N);
data_3 = randi(2, 1, N) - 1;
% data_3 = zeros(1, N);
data_4 = randi(2, 1, N) - 1;

symbols_1 = real(pskmod(data_1, M));
symbols_2 = real(pskmod(data_2, M));
symbols_3 = real(pskmod(data_3, M));
symbols_4 = real(pskmod(data_4, M));

% Allocating wide subcarriers to user 1, user 2 and user 3
ifft_sym_1 = ifft(symbols_1, N);
ifft_sym_2 = ifft(symbols_2, N);
ifft_sym_3 = ifft(symbols_3, N);

% Allocating narrow subcarrier to user 4
padded_sym_4 = interpolateNarrow(symbols_4);
ifft_sym_4 = ifft(padded_sym_4, N3);

%% Generating channel conditions

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

%% Power allocation schemes
P = 10;

[alpha1, alpha2, alpha3, beta4] = allocatePower_Four(h1, h2, h3, h4, 'manual', N_monte_carlo);

P_1 = sqrt(alpha1 * P);
P_2 = sqrt(alpha2 * P);
P_3 = sqrt(alpha3 * P);
P_4 = sqrt(beta4 * P);

SNR_in_dB = 2 : 1 : 20;

[ber_1, ber_2, ber_3, ber_4] = fourUsers(data_1, data_2, data_3, data_4, ifft_sym_1, ifft_sym_2, ifft_sym_3, ifft_sym_4, h1, h2, h3, h4, l_cp, P_1, P_2, P_3, P_4, N_monte_carlo, M, SNR_in_dB);

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

%% End time measurement

toc