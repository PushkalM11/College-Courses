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
            legend_list.append("Electric Field")
            continue
        
        row = data.strip().split(",")

        X.append(float(row[0].strip()))
        Y.append(float(row[1].strip()))

plt.legend(legend_list)

# plt.title("Electric Field vs Distance at equilibrium")
plt.title("Energy Band Diagram vs Distance at applied bias of 0.1V")
# plt.title("Energy Band Diagram vs Distance at applied bias of 0.3V")

plt.xlabel("Position (in μm)")
plt.ylabel("Electric Field (in V/cm)")

plt.show()