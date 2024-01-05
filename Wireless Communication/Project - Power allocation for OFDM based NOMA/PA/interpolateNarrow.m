function interpolated_signal = interpolateNarrow(signal)

    N = length(signal);
    interpolated_signal = zeros(1, 3 * N);
    for i = 1 : N
        interpolated_signal(3 * i) = signal(i);
    end

end