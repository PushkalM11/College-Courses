import matplotlib.pyplot as plt 

X = []
Y = []

legend = ["Vgs = 2V"]

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 9/NgSpice Code/Kn_Calculation.txt") as datafile:

	plotting = datafile.readlines()

	for data in plotting:

		row = data.strip().split("  ")

		X.append(float(row[0]))
		Y.append(1000*float(row[1]))

plt.plot(X, Y, color = "blue")

plt.title("Output Characteristics for calculating Kn", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.legend(legend)

plt.xlabel("Drain Voltage (in V)", fontdict={"font": "serif", "size": 18, "color": "black"})
plt.ylabel("Drain Current (in mA)", fontdict={"font": "serif", "size": 18, "color": "black"})


plt.show()