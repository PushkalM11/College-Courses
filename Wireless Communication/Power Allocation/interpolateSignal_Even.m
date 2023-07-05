function interpolated_signal = interpolateSignal_Even(signal)

    N = length(signal);
    interpolated_signal = zeros(1, 2 * N);
    for i = 1 : N
        interpolated_signal((2 * i) - 1) = signal(i);
    end

end