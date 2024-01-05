clc;
clear all;
close all;

[Ts, z_dB] = rayleigh_fading(1, 1000, 2);
plot(Ts, z_dB)

function [Ts, z_dB] = rayleigh_fading(f_D, t, f_s)
    if f_s < 1000
        f_s = 1000;
    end
    N = ceil(t * f_s);
    Ts = linspace(0, t, N);
    if mod(N, 2) == 1
        N = N + 1;
    end
    f = linspace(-f_s, f_s, N);
    
    Gfi_p = randn(2, (N / 2));
    CGfi_p = Gfi_p(1,:) + 1i * Gfi_p(2,:);
    CGfi = [conj(fliplr(CGfi_p)) CGfi_p];
    
    Gfq_p = randn(2, (N / 2));
    CGfq_p = Gfq_p(1,:) + 1i * Gfq_p(2,:);
    CGfq = [conj(fliplr(CGfq_p)) CGfq_p];
    
    omega_p = 1;
    S_r = (omega_p / (4 * pi)) ./ (f_D * sqrt(1 - (f / f_D).^2));
    
    idx1 = find(f>=f_D);
    idx2 = find(f<=-1*f_D);
    S_r(idx1) = 0; 
    S_r(idx2) = 0;
    S_r(idx1(1)) = S_r(idx1(1)-1);
    S_r(idx2(length(idx2))) = S_r(idx2(length(idx2))+1);
    
    r_I = N * ifft(CGfi .* sqrt(S_r));
    r_Q = -1j * N * ifft(CGfq .* sqrt(S_r));
    
    z = sqrt(abs(r_I).^2 + abs(r_Q).^2);
    z_dB = 20 * log10(z);
    z_dB = z_dB(1:length(Ts));
end