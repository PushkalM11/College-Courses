import numpy as np

def lrt(T):
    P1 = np.array([0.5, 0.35, 0.15])
    P2 = np.array([0.2, 0.3, 0.5])
    P1_X = np.zeros(27)
    P2_X = np.zeros(27)
    
    for i in range(27):
        b0 = i % 3
        b1 = int((i - b0) / 3) % 3
        b2 = int((i - b0 - b1 * 3) / 9)
        
        P1_X[i] = P1[b2] * P1[b1] * P1[b0]
        P2_X[i] = P2[b2] * P2[b1] * P2[b0]

    L = P1_X / P2_X
    
    A = 1 * (L > T)
    Ac = 1 - A
    
    alpha = np.sum(P1_X * Ac)
    beta = np.sum(P2_X * A)
    
    return alpha, beta