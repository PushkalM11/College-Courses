import matplotlib.pyplot as plt 

X = []
Y = []

legend = ["NOT Gate Output Voltage"]

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 8/NgSpice Codes/NOT_Gate.txt") as datafile:

	plotting = datafile.readlines()

	for data in plotting:

		row = data.strip().split("  ")

		X.append(float(row[0]))
		Y.append(float(row[1]))

plt.plot(X, Y, color = "blue")

plt.title("Vout vs Vin for NOT Gate", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.legend(legend)

plt.xlabel("Input Voltage Vin", fontdict={"font": "serif", "size": 18, "color": "black"})
plt.ylabel("Output Voltage Vout", fontdict={"font": "serif", "size": 18, "color": "black"})

plt.axvline(1.5, 0, 5, color="red", ls="--")
plt.axvline(2.289, 0, 5, color="red", ls="--")
plt.axvline(2.711, 0, 5, color="red", ls="--")
plt.axvline(3.67, 0, 5, color="red", ls="--")

plt.text(0.4, 2.441, "Region A", fontdict={"font": "serif", "size": 20, "color": "green"})
plt.text(1.59, 3.06, "Region B", fontdict={"font": "serif", "size": 20, "color": "green"})
plt.text(2.31, 4.74, "Region C", fontdict={"font": "serif", "size": 12, "color": "green"})
plt.text(2.9, 3.06, "Region D", fontdict={"font": "serif", "size": 20, "color": "green"})
plt.text(3.833, 2.441, "Region E", fontdict={"font": "serif", "size": 20, "color": "green"})

plt.show()