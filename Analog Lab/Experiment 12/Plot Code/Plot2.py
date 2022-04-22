import matplotlib.pyplot as plt
import numpy as np

legend_list = ["Theoretical", "Simulated"]

A = np.linspace(0, 5, 51)
Vout_avg_ideal = np.linspace(0, 3.3, 51)
Vout_avg = [0, 0.065, 0.133, 0.202, 0.268, 0.34, 0.402, 0.469, 0.54, 0.6, 0.67, 0.74, 0.8, 0.87, 0.94, 1, 1.07, 1.14, 1.21, 1.27, 1.34, 1.41, 1.48, 1.55, 1.61, 1.68, 1.75, 1.82, 1.89, 1.96, 2.02, 2.09, 2.16, 2.23, 2.30, 2.36, 2.42, 2.5, 2.56, 2.63, 2.69, 2.77, 2.82, 2.90, 2.99, 3.04, 3.09, 3.13, 3.17, 3.20, 3.23]

plt.plot(A, Vout_avg_ideal, color = "green", ls = "--")
plt.plot(A, Vout_avg, color = "blue", marker = "o", ls = "-")

plt.title("At 2.5kHz", size = 25)

plt.xlabel("Amplitude of Input Wave (in Volts)", size = 18)
plt.ylabel("Average $V_o$ (in Volts)", size = 18)

plt.grid()

plt.legend(legend_list)

plt.show()