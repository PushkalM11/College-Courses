import numpy as np
from Serial_36 import HammingDecoder as HD_36
from Serial_50 import HammingDecoder as HD_50

def convert_int_to_binary(num, digits):
    binary = np.zeros(digits)
    k = digits - 1
    while num:
        binary[k] = num % 2
        num = num // 2
        k -= 1
    return binary

# for i in range(2 ** 15):
# 	binary = convert_int_to_binary(i, 15)
# 	c1 = HD_50(binary)
# 	binary = convert_int_to_binary(i, 15)
# 	c2 = HD_36(binary)
# 	print(convert_int_to_binary(i, 15))
# 	if np.any(c1 != c2):
# 		print(c1)
# 		print(c2)
# 		print("Error at:", i)
# 		break

codeword = [0] * 15
for i in range(15):
	codeword = [0] * 15
	codeword[i] = 1
	print(HD_36(np.array(codeword)))
	print(HD_50(np.array(codeword)))