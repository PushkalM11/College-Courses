function wideSubcarrier = recoverWide_Four(signal)

    N = length(signal);
    k = N / 2;
    wideSubcarrier = zeros(1, k);
    for i = 1 : k
        wideSubcarrier(i) = signal(2 * i - 1);
    end

end