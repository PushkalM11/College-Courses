import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 7/NgSpice Codes/transfer_characteristics.txt") as datafile:

    plotting = datafile.readlines()   

    for data in plotting:
    
        row = data.strip().split("  ")
    
        if "1.25Volts" in row:
            plt.plot(X, Y, color = "red")
            X = []
            Y = []
            legend_list.append("Vd = 1.25V")
            continue

        if "2.5Volts" in row:
            plt.plot(X, Y, color = "blue")
            X = []
            Y = []
            legend_list.append("Vd = 2.5V")
            continue 

        X.append(float(row[0]))
        Y.append(1000*float(row[1]))

plt.legend(legend_list)

plt.title("The Transfer Characteristics of PMOSFET", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.xlabel("Vg (in Volts)")
plt.ylabel("Id (in mA)")

plt.show()