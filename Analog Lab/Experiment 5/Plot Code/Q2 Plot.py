import matplotlib.pyplot as plt
import numpy as np

legend_list = ["Theoretical", "Simulated"]
Vc = np.linspace(4, 6, 21)
Frequency = [9.19, 9.42, 9.60, 9.86, 10.00, 10.23, 10.35, 10.58, 10.80, 11.07, 11.20, 11.44, 11.60, 11.75, 12.00, 12.20, 12.40, 12.63, 12.80, 13.00, 13.20]
Ideal_Frequency = np.linspace(10, 15, 21)

plt.plot(Vc, Ideal_Frequency, color = "red", marker = "o", ls = "-.")
plt.plot(Vc, Frequency, color = "blue", marker = "o", ls = "-.")

plt.title("Frequency vs Vc Characteristics Plot", size = 25)

plt.xlabel("Vc (in Volts)", size = 18)
plt.ylabel("Frequency (in kHz)", size = 18)

plt.legend(legend_list)

plt.show()