import matplotlib.pyplot as plt
import numpy as np

k = np.linspace(1, 3, 9)
Vout_steady_state = [1.05, 1.38, 1.75, 2.12, 2.48, 2.87, 3.24, 3.33, 3.34]

plt.plot(k, Vout_steady_state, color = "blue", marker = "o", ls = "-")

plt.title("Steady State Vout vs k Plot", size = 25)

plt.xlabel("k", size = 18)
plt.ylabel("Steady State Vout (in Volts)", size = 18)

plt.grid()

plt.show()