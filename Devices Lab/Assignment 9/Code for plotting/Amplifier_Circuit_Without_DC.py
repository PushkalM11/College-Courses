import matplotlib.pyplot as plt 

X = []
Y = []
i = 1

legend = ["Vin", "Vout"]

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 9/NgSpice Code/Amplifier_Circuit.txt") as datafile:

	plotting = datafile.readlines()

	lines = len(plotting)
	l1 = lines / 2

	for data in plotting:

		row = data.strip().split(" ")

		if '' in row:
			row.remove('')
		
		X.append(1000*float(row[0]))
		Y.append(float(row[1]))

		if i == l1:
			Vin_max = max(Y)
			plt.plot(X, Y, color = "blue")
			X = []
			Y = []

		if i == lines:
			DC_Bias = (float) (sum(Y) / len(Y))
			for j in range(len(Y)):
				Y[j] -= DC_Bias
			Vout_max = max(Y)
			plt.plot(X, Y, color = "red")
			X = []
			Y = []

		i += 1

plt.title("Voltage vs Time without DC Bias", size = 25)

plt.legend(legend)

plt.xlabel("Time (in ms)", size = 18)
plt.ylabel("Voltage (in V)", size = 18)
plt.text(1.68, -0.3, f'Amplification = -{round(Vout_max / Vin_max, 3)}', fontdict={"font": "serif", "size": 13, "color": "green"})

print(f'The amplification of the circuit is -{Vout_max / Vin_max}')

plt.show()