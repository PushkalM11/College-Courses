function narrowSubcarrier = recoverNarrow_Four(signal)

    N = length(signal);
    k = N / 3;
    narrowSubcarrier = zeros(1, k);
    for i = 1 : k
        narrowSubcarrier(i) = signal(3 * i);
    end

end