import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 7/NgSpice Codes/output_characteristics.txt") as datafile:

    plotting = datafile.readlines()   

    for data in plotting:
    
        row = data.strip().split("  ")
    
        if "1.25Volts" in row:
            plt.plot(X, Y, color = "red", linewidth = 2.5)
            X = []
            Y = []
            legend_list.append("Vg = 1.25V")
            continue

        if "2.5Volts" in row:
            plt.plot(X, Y, color = "blue", linewidth = 2.5)
            X = []
            Y = []
            legend_list.append("Vg = 2.5V")
            continue 

        X.append(float(row[0]))
        Y.append(1000*float(row[1]))

plt.legend(legend_list)

plt.title("The Output Characteristics of PMOSFET", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.xlabel("Vd (in Volts)")
plt.ylabel("Id (in mA)")

plt.axvline(0, 0, 0.045, color="red", ls="-")
plt.axvline(1.82, 0, 0.309, color="red", ls="--")
plt.axvline(5.19, 0, 0.38, color="red", ls="--")
plt.axvline(3.33, 0, 0.57, color="blue", ls="-.")
plt.axvline(6.8, 0, 0.68, color="blue", ls="-.")

plt.text(0.66, 0.2, "Ohmic", fontdict={"font": "serif", "size": 20, "color": "red"})
plt.text(2.85, 0.9, "Saturation", fontdict={"font": "serif", "size": 20, "color": "red"})
plt.text(6.9, 1.5, "Breakdown", fontdict={"font": "serif", "size": 20, "color": "red"})
plt.text(1, 1.5, "Ohmic", fontdict={"font": "serif", "size": 20, "color": "blue"})
plt.text(4, 2.3, "Saturation", fontdict={"font": "serif", "size": 20, "color": "blue"})
plt.text(7, 3.05, "Breakdown", fontdict={"font": "serif", "size": 20, "color": "blue"})

plt.show()