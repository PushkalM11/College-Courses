function odd_signal = returnOddSignal(signal)

N = length(signal);
k = N / 2;
odd_signal = zeros(1, k);
for i = 1 : k
    odd_signal(i) = signal(2 * i);
end

end