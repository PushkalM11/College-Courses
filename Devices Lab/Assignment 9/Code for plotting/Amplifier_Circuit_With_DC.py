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
			plt.plot(X, Y, color = "blue")
			X = []
			Y = []

		if i == lines:
			DC_Bias = (float) (sum(Y) / len(Y))
			plt.plot(X, Y, color = "red")
			X = []
			Y = []

		i += 1

plt.title("Voltage vs Time with DC Bias", size = 25)

plt.legend(legend)

plt.xlabel("Time (in ms)", size = 18)
plt.ylabel("Voltage (in V)", size = 18)

plt.text(0.73, 7.34, f'DC Bias = {round(DC_Bias, 3)}', fontdict={"font": "serif", "size": 13, "color": "red"})

print(f'The DC Bias of the circuit is {DC_Bias}')

plt.show()