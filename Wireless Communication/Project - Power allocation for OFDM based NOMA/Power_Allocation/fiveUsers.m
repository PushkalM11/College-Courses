function [ber_1, ber_2, ber_3, ber_4, ber_5] = fiveUsers(data_1, data_2, data_3, data_4, data_5, ifft_sym_1, ifft_sym_2, ifft_sym_3, ifft_sym_4, ifft_sym_5, h1, h2, h3, h4, h5, l_cp, P_1, P_2, P_3, P_4, P_5, N_monte_carlo, M, SNR_in_dB)
    
    N = length(data_1);
    N2 = 2 * N;
    N3 = 3 * N;
    N4 = 4 * N;
    
    SNR = 10 .^ (SNR_in_dB / 10);
    
    ber_1 = zeros(1, length(SNR));
    ber_2 = zeros(1, length(SNR));
    ber_3 = zeros(1, length(SNR));
    ber_4 = zeros(1, length(SNR));
    ber_5 = zeros(1, length(SNR));

    for i = 1 : length(SNR)
        
        ber_1_temp = 0;
        ber_2_temp = 0;
        ber_3_temp = 0;
        ber_4_temp = 0;
        ber_5_temp = 0;
        
        for jj = 1 : N_monte_carlo
            
            x_transmitted = zeros(1, N2);
            x_transmitted(1 : N) = P_1(jj) * ifft_sym_1;
            x_transmitted(N + 1 : N2) = P_2(jj) * ifft_sym_2;
            x_transmitted(N2 + 1 : N3) = P_3(jj) * ifft_sym_3;
            x_transmitted(N3 + 1 : N4) = P_4(jj) * ifft_sym_4;
            x_transmitted = x_transmitted + (P_5(jj) * ifft_sym_5);

            % Adding cyclic prefix to symbols
            len_x_cp = N2 + l_cp;
            x_cp_transmitted = [x_transmitted((N2 - l_cp + 1) : N2), x_transmitted];
            
            % Signal received at User 1  adds awgn
            y1 = awgn(h1(jj) .* x_cp_transmitted, SNR(i),'measured'); 
            % Signal received at User 2
            y2 = awgn(h2(jj) .* x_cp_transmitted, SNR(i),'measured');
            % Signal received at User 3
            y3 = awgn(h3(jj) .* x_cp_transmitted, SNR(i),'measured');
            % Signal received at User 4
            y4 = awgn(h4(jj) .* x_cp_transmitted, SNR(i),'measured');
            % Signal received at User 5
            y5 = awgn(h5(jj) .* x_cp_transmitted, SNR(i),'measured');

            % Equalisation at receivers
            r_eq_1 = y1 ./ h1(jj);
            r_eq_2 = y2 ./ h2(jj);
            r_eq_3 = y3 ./ h3(jj);
            r_eq_4 = y4 ./ h4(jj);
            r_eq_5 = y5 ./ h5(jj);

            % CP removed received signal
            r_eq_1 = r_eq_1(l_cp + 1 : end);
            r_eq_2 = r_eq_2(l_cp + 1 : end);
            r_eq_3 = r_eq_3(l_cp + 1 : end);
            r_eq_4 = r_eq_4(l_cp + 1 : end);
            r_eq_5 = r_eq_5(l_cp + 1 : end);

            % FFT operation at User 1 and User 3
            fft_r_1_tmp = fft(r_eq_1);
            fft_r_2_tmp = fft(r_eq_2);
            fft_r_3_tmp = fft(r_eq_3);
            fft_r_4_tmp = fft(r_eq_4);
            fft_r_5_tmp = fft(r_eq_5);

            fft_r_1 = function_Recover_Even_Subcarriers(fft_r_1_tmp);
            fft_r_2 = function_Recover_Even_Subcarriers(fft_r_2_tmp);
            fft_r_3 = function_Recover_Even_Subcarriers(fft_r_3_tmp);
            fft_r_4 = function_Recover_Even_Subcarriers(fft_r_4_tmp);
            fft_r_5 = function_Recover_Even_Subcarriers(fft_r_5_tmp);

            % At User 4 -------------------------------
            % Direct decoding as higher power allocated
            x_4_hat= pskdemod(fft_r_4, M);
            ber_4_temp= ber_4_temp + calculateBER(data_4, x_4_hat);

            % At User 1 -------------------------------
            % Decoding User 4's signal first then removing it
            x_4_at_1 = pskdemod(fft_r_1, M);
            x_4_at_1= real(pskmod(x_4_at_1, M));
            y_1 = fft_r_1 - (P_4(jj) * x_4_at_1);
            x_1_hat = pskdemod(y_1, M);
            ber_1_temp = ber_1_temp + calculateBER(data_1, x_1_hat);

            % At User 3 -------------------------------
            % Decoding User 4 and User 1 signal first then removing it
            x_4_at_3 = pskdemod(fft_r_3, M);
            x_4_at_3 = real(pskmod(x_4_at_3, M));

            y_1_at_3 = fft_r_3 - (P_4(jj) * x_4_at_3);
            x_1_at_3 = pskdemod(y_1_at_3, M);
            x_1_at_3= real(pskmod(x_1_at_3, M));

            y_3_hat= fft_r_3 - (P_4(jj) * x_4_at_3 + P_1(jj) * x_1_at_3);
            x_3_hat = pskdemod(y_3_hat, M);
            ber_3_temp = ber_3_temp + calculateBER(data_3, x_3_hat);

            % At User 2 -------------------------------
            % Decoding User 4, User 1 and User 2 signal first then removing it
            x_4_at_2 = pskdemod(fft_r_2, M);
            x_4_at_2 = real(pskmod(x_4_at_2, M));

            y_1_at_2 = fft_r_2 - (P_4(jj) * x_4_at_2);
            x_1_at_2 = pskdemod(y_1_at_2, M);
            x_1_at_2= real(pskmod(x_1_at_2, M));

            y_3_at_2 = fft_r_2 - (P_4(jj) * x_4_at_2 + P_1(jj) * x_1_at_2);
            x_3_at_2 = pskdemod(y_3_hat, M);

            y_2_hat = y_3_at_2 - (P_3(jj) * x_3_at_2);
            x_2_hat = pskdemod(y_2_hat, M);
            ber_2_temp = ber_2_temp + calculateBER(data_2, x_2_hat);

        end

        ber_1(i) = ber_1_temp / N_monte_carlo;
        ber_2(i) = ber_2_temp / N_monte_carlo;
        ber_3(i) = ber_3_temp / N_monte_carlo;
        ber_4(i) = ber_4_temp / N_monte_carlo;
        
    end
    
end