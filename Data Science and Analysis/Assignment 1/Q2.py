from scipy import stats  
import numpy as np
import matplotlib.pyplot as plt

draws = np.arange(-5.5, 5.5, 0.01)

cauchy_distribution = stats.cauchy(0, 1.5)
cauchy_pdf = cauchy_distribution.pdf(draws)

normal_distribution = stats.norm(0, 1.5)
normal_pdf = normal_distribution.pdf(draws)

legend = ["Cauchy Distribution: μ = 0 and γ = 1.5", "Normal Distribution: μ = 0, σ = 1.5"]
plt.plot(draws, cauchy_pdf, color = "blue")
plt.plot(draws, normal_pdf, color = "green", ls = "--")
plt.title("PDF for Cauchy and Gaussian distributions", size = 21)
plt.xlabel("Random Variable Values x", size = 19)
plt.ylabel("Probability Density", size = 19)
plt.legend(legend)
plt.show()