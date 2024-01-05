import numpy as np

def HammingDecoder(y):

    H = np.zeros((4,15))
    
    def find_bin(num):
        
        binary = np.zeros(4)
        i = 3
        while(num):
            binary[i] = num % 2
            num = num//2
            i = i - 1
        return binary
    
    for i in range(1,16):
        binary = find_bin(i)
        H[:,i-1] = binary

    syn = np.matmul(H,y)
    syn = syn % 2
    
    def find_num(binary):
        
        num = (binary[0] * 8) + (binary[1] * 4) + (binary[2] * 2) + (binary[3] * 1)
        return num
    
    bit_flip_position = find_num(syn)
    
    if(bit_flip_position != 0):
        
        index = int(bit_flip_position - 1)
        y[index] = (y[index] + 1) % 2
        
    return y        