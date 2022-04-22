import matplotlib.pyplot as plt
import numpy as np

legend_list = ["Theoretical", "Simulated"]

A = np.linspace(0, 5, 51)
Vout_avg_ideal = np.linspace(0, 3.3, 51)
Vout_avg = [0, 0.065, 0.131, 0.198, 0.265, 0.33, 0.4, 0.47, 0.53, 0.6, 0.67, 0.74, 0.8, 0.87, 0.94, 1, 1.07, 1.14, 1.2, 1.28, 1.34, 1.41, 1.48, 1.545, 1.61, 1.68, 1.746, 1.82, 1.87, 1.95, 2.01, 2.08, 2.15, 2.21, 2.28, 2.35, 2.42, 2.48, 2.55, 2.62, 2.686, 2.75, 2.82, 2.88, 2.958, 3.01, 3.048, 3.08, 3.13, 3.17, 3.18]

plt.plot(A, Vout_avg_ideal, color = "green", ls = "--")
plt.plot(A, Vout_avg, color = "blue", marker = "o", ls = "-")

plt.title("At 5kHz", size = 25)

plt.xlabel("Amplitude of Input Wave (in Volts)", size = 18)
plt.ylabel("Average $V_o$ (in Volts)", size = 18)

plt.grid()

plt.legend(legend_list)

plt.show()