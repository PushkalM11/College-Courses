import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 7/NgSpice Codes/dibl_1um_transfer.txt") as datafile:

    plotting = datafile.readlines()   

    for data in plotting:
    
        row = data.strip().split("  ")
    
        if "0.1Volts" in row:
            plt.semilogy(X, Y, color = "red")
            X = []
            Y = []
            legend_list.append("Vd = 0.1V")
            continue

        if "2.5Volts" in row:
            plt.semilogy(X, Y, color = "blue")
            X = []
            Y = []
            legend_list.append("Vd = 2.5V")
            continue 

        X.append(float(row[0]))
        Y.append(float(row[1]))

plt.legend(legend_list)

plt.title("The Transfer Characteristics of PMOSFET for L = 1μm", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.axhline(1E-8, 0.465, 0.47, color="black", ls="-")

plt.xlabel("Vg (in Volts)")
plt.ylabel("log(Id)")

plt.show()