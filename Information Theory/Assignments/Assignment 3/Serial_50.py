import numpy as np 

def convert_int_to_binary(num, digits):
    binary = np.zeros(digits)
    k = digits - 1
    while num:
        binary[k] = num % 2
        num = num // 2
        k -= 1
    return binary

def generate_H_matrix(shape):
    M, N = shape
    H = np.zeros(shape)
    for j in range(N):
        H[ : , j] = np.array(convert_int_to_binary(j + 1, M))
    return H

def convert_binary_to_int(binary):
    integer = 0
    bits = len(binary)
    for i, val in enumerate(binary):
        integer += (val * (2 ** (bits - i - 1)))
    return int(integer)

def HammingDecoder(y):
    y = y.reshape([15, 1])
    H = generate_H_matrix([4, 15])
    syndrome = H @ y
    s = syndrome % 2
    index_to_flip = convert_binary_to_int(s)
    if index_to_flip != 0:
        y[index_to_flip - 1] = (1 if y[index_to_flip - 1] == 0 else 0)
    return y.reshape([15]).tolist()