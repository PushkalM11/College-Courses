clc;
clear all;
close all;

m = [1, 2, 4];
SNR = 0:0.01:20;
P_b_bar = zeros(length(SNR));
gamma_b = 10 .^ (SNR / 10);

f1 = figure(1);
line_style = ['-r', '-b', '-k'];

fprintf('At SNR = 10dB \n');
fprintf('m     BER\n');

for i = 1 : length(m)
   
   for j = 1 : length(gamma_b)
       
       syms phi
       integrand = (1 + (gamma_b(j) / (m(i) * (sin(phi) .^ 2)))) .^ (-m(i));
       integral = (1 / pi) * vpaintegral(integrand, phi, [0 (pi / 2)]);
       P_b_bar(j) = vpa(integral);
       
       if SNR(j) == 10
           
           fprintf('%d   %f\n', m(i), integral);
           
       end
       
   end

   semilogy(SNR, P_b_bar, line_style(i));
   hold on;
    
end

legend('m = 1', 'm = 2', 'm = 4');
title('Plots of P_b using BPSK modulation for Nakagami Fading with m = 1, 2, 4');
ylabel('Average Bit Error Probability (BER)');
xlabel('Average SNR (in dB)');
