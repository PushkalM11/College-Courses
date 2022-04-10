import matplotlib.pyplot as plt
import numpy as np

Vr = np.linspace(-2.5, 2.5, 25)
Vout_steady_state = [-0.47, -0.45, -0.4, -0.27, -0.16, -0.05, 0.11, 0.2, 0.3, 0.5, 0.6, 0.7, 0.79, 0.9, 1, 1.15, 1.3, 1.4, 1.47, 1.6, 1.73, 1.82, 2.05, 2.07, 2.1]

plt.plot(Vr, Vout_steady_state, color = "blue", marker = "o", ls = "-")

plt.title("Steady State Vout vs Control Voltage Plot", size = 25)

plt.xlabel("Control Voltage Vr (in Volts)", size = 18)
plt.ylabel("Steady State Vout", size = 18)

plt.grid()

plt.show()