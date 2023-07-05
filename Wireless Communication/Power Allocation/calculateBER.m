function BER = calculateBER(transmitted_bits, received_bits)

N = length(received_bits);
BER = sum(abs(received_bits - transmitted_bits)) / N;

end

