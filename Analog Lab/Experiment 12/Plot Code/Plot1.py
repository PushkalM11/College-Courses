import matplotlib.pyplot as plt
import numpy as np

legend_list = ["Theoretical", "Simulated"]

A = np.linspace(0, 5, 51)
Vout_avg_ideal = np.linspace(0, 3.5, 51)
Vout_avg = [0, 0.069, 0.137, 0.202, 0.27, 0.34, 0.4, 0.47, 0.54, 0.6, 0.67, 0.74, 0.81, 0.88, 0.95, 1, 1.15, 1.21, 1.28, 1.35, 1.42, 1.49, 1.55, 1.62, 1.69, 1.75, 1.82, 1.89, 1.96, 2.02, 2.09, 2.16, 2.23, 2.30, 2.36, 2.43, 2.5, 2.56, 2.63, 2.70, 2.77, 2.84, 2.90, 2.99, 3.05, 3.08, 3.12, 3.17, 3.2, 3.23, 3.25]

plt.plot(A, Vout_avg_ideal, color = "green", ls = "--")
plt.plot(A, Vout_avg, color = "blue", marker = "o", ls = "-")

plt.title("At 100Hz", size = 25)

plt.xlabel("Amplitude of Input Wave (in Volts)", size = 18)
plt.ylabel("Average $V_o$ (in Volts)", size = 18)

plt.grid()

plt.legend(legend_list)

plt.show()