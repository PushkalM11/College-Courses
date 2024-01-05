function noise = gaussian_noise(mean, SNR, len)

sigma = 1 / sqrt(SNR);
noise = mean + sigma * randn([1, len]);

end

