function wideSubcarrier = recoverWide_Four(signal)

    N = length(signal);
    k = N / 3;
    wideSubcarrier = zeros(1, k);
    for i = 1 : k
        wideSubcarrier(i) = signal(3 * i - 2);
    end

end