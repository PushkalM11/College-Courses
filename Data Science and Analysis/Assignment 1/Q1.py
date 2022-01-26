import scipy
from scipy import stats  
import numpy as np
import matplotlib.pyplot as plt
from astroML import stats as asts

n = 1000
mean = 1.5
stddev = 0.5

distribution = stats.norm(mean, stddev)
draws = distribution.rvs(n)
draws.sort()
pdf = distribution.pdf(draws)

legend = ["μ = 1.5, σ = 0.5"]
plt.plot(draws, pdf, color = "blue")
plt.title("Probability Density Function for Normal Random Variable", size = 21)
plt.xlabel("x", size = 19)
plt.ylabel("p(x|μ,σ)", size = 19)
plt.legend(legend)
plt.show()

mean = np.mean(draws)
print(f'The mean of the given sample is: {mean}')

variance = np.var(draws)
print(f'The variance of the given sample is: {variance}\nThe standard deviation of the given sample is: {pow(variance, 0.5)}')

skewness = scipy.stats.skew(draws)
print(f'The skewness of the given sample is: {skewness}')

kurtosis = scipy.stats.kurtosis(draws)
print(f'The kurtosis of the given sample is: {kurtosis}')

median_draws = np.median(draws)
corr_draws = np.zeros(np.size(draws))
i = 1
for xi in draws:
	corr_draws = abs(xi - median_draws)
	i += 1
mad = np.median(corr_draws)
stddev_using_mad = 1.482 * mad 
print(f'The standard deviation using MAD: {stddev_using_mad}')

stddev_using_sigmaG = asts.sigmaG(draws)
print(f'The standard deviation using sigmaG: {stddev_using_sigmaG}')