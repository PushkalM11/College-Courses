function even_subcarrier = function_Recover_Even_Subcarriers(signal)

    N = length(signal);
    k = N / 2;
    even_subcarrier = zeros(1, k);
    for i = 0 : k-1
        even_subcarrier(i+1) = signal(2 * i + 1);
    end

end