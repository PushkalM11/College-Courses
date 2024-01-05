# import the function from your submission "Serial_50.py"
from Serial_50 import lrt

# threshold for likelihood ratio test
T = 0.75

# computing type-I and type-II error rates
alpha, beta = lrt(T)

print(alpha, beta)