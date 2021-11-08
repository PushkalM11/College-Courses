import matplotlib.pyplot as plt 
import numpy as np

X = [[], [], []]
Y = [[], [], []]

check = [14.5, 8.5, 2.5]
logic_values = [[], [], []]
for asd in range(0, 10):
	logic_values[0].append(0)
	logic_values[1].append(0)
	logic_values[2].append(0)
min_time = 5E-8
time = min_time

i = 1
j = 0
index = 1

legend = ["Vin1", "Vin2", "Output"]

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 8/NgSpice Codes/AND_Gate.txt") as datafile:

	plotting = datafile.readlines()

	lines = len(plotting)
	l1 = lines / 3
	l2 = l1*2

	for data in plotting:

		row = data.strip().split(" ")
		
		if '' in row:
			row.remove('')

		if float(row[1]) > check[j]:

			logic_values[j][index-1] = 1

		else:
		
			logic_values[j][index-1] = 0
		
		if index * min_time > float(row[0]):
			print('')

		else:
			index += 1
			time = index * min_time	
			
		X[j].append(float(row[0]))
		Y[j].append(float(row[1]))

		if i == l1:
			plt.plot(X[j], Y[j], color = "blue")
			j += 1
			index = 1

		if i == l2:
			plt.plot(X[j], Y[j], color = "red")
			j += 1
			index = 1

		if i == lines:
			plt.plot(X[j], Y[j], color = "green")
			j += 1
			exit

		i += 1

plt.title("Vout vs Time for AND Gate", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.legend(legend)

plt.xlabel("Time (in 100ns)", fontdict={"font": "serif", "size": 18, "color": "black"})
plt.ylabel("Output Voltage Vout", fontdict={"font": "serif", "size": 18, "color": "black"})

for i in range(0, 10):
	plt.text(2.5E-8 + min_time * i, 14.5, f"{logic_values[0][i]}", fontdict={"font": "serif", "size": 20, "color": "blue"})
	plt.text(2.5E-8 + min_time * i, 8.5, f"{logic_values[1][i]}", fontdict={"font": "serif", "size": 20, "color": "red"})
	plt.text(2.5E-8 + min_time * i, 2.5, f"{logic_values[2][i]}", fontdict={"font": "serif", "size": 20, "color": "green"})

plt.show()