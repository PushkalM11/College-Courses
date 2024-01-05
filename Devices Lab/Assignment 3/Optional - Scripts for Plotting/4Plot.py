import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

with open("sample.txt") as datafile:

    plotting = datafile.readlines()
    
    for data in plotting:
        
        if "end" in data:
            plt.plot(X, Y, color="blue", ls="-")
            X = []
            Y = []
            legend_list.append("Current")
            continue
        
        row = data.strip().split(",")

        X.append(float(row[0].strip()))
        Y.append(float(row[1].strip()))

plt.legend(legend_list)

plt.title("I-V Characteristics")

plt.xlabel("Voltage (in V)")
plt.ylabel("Current (in A/cm2)")

plt.show()