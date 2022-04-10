import matplotlib.pyplot as plt
import numpy as np

legend_list = ["Theoretical"]
Vc = np.linspace(4, 6, 21)
Frequency = [54.44, 55.54, 55.62, 56.66, 57.77, 58.87, 58.90, 60.00, 60.10, 62.20, 61.10, 63.32, 63.40, 64.45, 64.60, 65.56, 65.65, 65.70, 67.80, 68.80, 68.90]

plt.plot(Vc, Frequency, color = "blue", marker = "o", ls = "-.")

plt.title("Frequency vs Vc Characteristics Plot", size = 25)

plt.xlabel("Vc (in Volts)", size = 18)
plt.ylabel("Frequency (in kHz)", size = 18)

plt.legend(legend_list)

plt.show()