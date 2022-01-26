from scipy import stats  
import numpy as np
import matplotlib.pyplot as plt

poisson_draws = np.arange(-2, 15, 1)
normal_draws = np.arange(-2, 15, 0.01)

poisson_distribution = stats.poisson(5)
poisson_pdf = poisson_distribution.pmf(poisson_draws)

normal_distribution = stats.norm(5, pow(5, 0.5))
normal_pdf = normal_distribution.pdf(normal_draws)

legend = ["Poisson Distribution: μ = 5", "Normal Distribution: μ = 5, σ = " + r"$\sqrt{5}$"]
plt.step(poisson_draws, poisson_pdf, color = "green", ls = "--")
plt.plot(normal_draws, normal_pdf, color = "blue")
plt.title("PDF for Poisson and Gaussian distributions", size = 21)
plt.xlabel("Random Variable Values x", size = 19)
plt.ylabel("Probability Density", size = 19)
plt.legend(legend)
plt.show()