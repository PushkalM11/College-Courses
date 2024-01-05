import numpy as np

def mutual_information(pmf, i, j):

    pmf_i = np.zeros(10)
    pmf_j = np.zeros(10)
    pmf_ij = np.zeros([10, 10])
    
    scale_i = [1, 10, 100, 1000]
    scale_j = [1, 10, 100, 1000]
    scale_ij = [1, 10, 100, 1000]
    
    val_i = scale_i.pop(i)
    scale_i = np.array(scale_i)
    val_j = scale_j.pop(j)
    scale_j = np.array(scale_j)
    scale_ij.remove(val_i)
    scale_ij.remove(val_j)
    
    for a in range(10):
        for ax in range(10):
            for ay in range(10):
                for az in range(10):
                    mul = np.array([az, ay, ax])
                    index_i = np.dot(mul, scale_i) + (a * val_i)
                    index_j = np.dot(mul, scale_j) + (a * val_j)
                    pmf_i[a] += pmf[index_i]
                    pmf_j[a] += pmf[index_j]
    
    for ai in range(10):
        for aj in range(10):
            for ax in range(10):
                for ay in range(10):
                    index_ij = np.dot(np.array([ay, ax]), scale_ij) + (aj * val_j) + (ai * val_i)
                    pmf_ij[ai][aj] += pmf[index_ij]
    
    answer = 0
    
    for ai in range(10):
        for aj in range(10):
            answer += (pmf_ij[ai][aj] * np.log2(pmf_ij[ai][aj] / (pmf_i[ai] * pmf_j[aj])))
    
    return answer