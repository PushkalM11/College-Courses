import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

with open("sample.txt") as datafile:

    plotting = datafile.readlines()
    
    for data in plotting:
        
        if "electron" in data:
            plt.semilogy(X, Y, color="red", ls="-")
            X = []
            Y = []
            legend_list_list.append("Electron Density")
            continue

        if "hole" in data:
            plt.semilogy(X, Y, color="blue", ls="--")
            X = []
            Y = []
            legend_list.append("Hole Density")
            continue
        
        row = data.strip().split(",")

        X.append(float(row[0].strip()))
        Y.append(float(row[1].strip()))

plt.legend(legend_list)

# plt.title("Energy Band Diagram vs Distance at equilibrium")
# plt.title("Energy Band Diagram vs Distance at applied bias of 0.1V")
plt.title("Energy Band Diagram vs Distance at applied bias of 0.3V")

plt.xlabel("Position (in μm)")
plt.ylabel("Concentration (in 1/cm3)")

plt.show()