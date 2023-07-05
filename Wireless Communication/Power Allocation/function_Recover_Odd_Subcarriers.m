function odd_subcarrier = function_Recover_Odd_Subcarriers(signal)

    N = length(signal);
    k = N / 2;
    odd_subcarrier = zeros(1, k);
    for i = 1 : k-1
        odd_subcarrier(i) = signal(2 * i);
    end

end