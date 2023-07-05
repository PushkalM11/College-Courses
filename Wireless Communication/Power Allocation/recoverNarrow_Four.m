function narrowSubcarrier = recoverNarrow_Four(signal)

    N = length(signal);
    k = N / 2;
    narrowSubcarrier = zeros(1, k);
    for i = 1 : k
        narrowSubcarrier(i) = signal(2 * i);
    end

end