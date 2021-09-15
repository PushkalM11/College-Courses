import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

with open("sample.txt") as datafile:

    plotting = datafile.readlines()
    
    for data in plotting:
        
        if "quasi" in data:
            plt.plot(X, Y, color="red", ls="-.")
            X = []
            Y = []
            legend_list.append("Quasi Fermi Level")
            continue

        if "Ei" in data:
            plt.plot(X, Y, color="grey", ls="--")
            X = []
            Y = []
            legend_list.append("Ei")
            continue

        if "Ec" in data:
            plt.plot(X, Y, color="blue", ls="-")
            X = []
            Y = []
            legend_list.append("Ec")
            continue

        if "Ev" in data:
            plt.plot(X, Y, color="blue", ls="-")
            X = []
            Y = []
            legend_list.append("Ev")
            continue

        if "Efn" in data:
            plt.plot(X, Y, color="red", ls="-")
            X = []
            Y = []
            legend_list.append("Quasi Fermi Level of Electrons")
            continue

        if "Efp" in data:
            plt.plot(X, Y, color="orange", ls="-.")
            X = []
            Y = []
            legend_list.append("Quasi Fermi Level of Holes")
            continue
        
        row = data.strip().split(",")

        X.append(float(row[0].strip()))
        Y.append(float(row[1].strip()))

plt.legend(legend_list)

# plt.title("Energy Band Diagram vs Distance at equilibrium")
# plt.title("Energy Band Diagram vs Distance at applied bias of 0.1V")
plt.title("Energy Band Diagram vs Distance at applied bias of 0.3V")

plt.xlabel("Position (in μm)")
plt.ylabel("Energy (in eV)")

plt.show()