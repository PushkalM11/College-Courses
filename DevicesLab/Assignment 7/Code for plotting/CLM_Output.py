import matplotlib.pyplot as plt
  
X = []
Y = []
legend_list = []

slope = []

with open("/Users/pushkalmishra/Desktop/Semester 3/Devices Lab/Experiment 7/NgSpice Codes/clm_output.txt") as datafile:

    plotting = datafile.readlines()   

    for data in plotting:
    
        row = data.strip().split("  ")
    
        if "500nm" in row:
            plt.plot(X, Y, color = "red")
            X = []
            Y = []
            legend_list.append("L = 500nm")
            continue

        if "1um" in row:
            plt.plot(X, Y, color = "blue")
            X = []
            Y = []
            legend_list.append("L = 1μm")
            continue 

        if float(row[0]) == 3:
            slope.append(1000*float(row[1]))
        if float(row[0]) == 4:
            slope.append(1000*float(row[1]))
        X.append(float(row[0]))
        Y.append(1000*float(row[1]))

slope_500nm = round(1000*(slope[1] - slope[0]), 3)
slope_1um = round(1000*(slope[3] - slope[2]), 3)

plt.legend(legend_list)

plt.title("The Output Characteristics of PMOSFET", fontdict={"font": "serif", "size": 25, "color": "black"})

plt.xlabel("Vd (in Volts)")
plt.ylabel("Id (in mA)")

plt.text(2.5, 1.3, f'Slope = {slope_500nm}μA/V', fontdict={"font": "serif", "size": 20, "color": "red"})
plt.text(2.5, 0.75, f'Slope = {slope_1um}μA/V', fontdict={"font": "serif", "size": 20, "color": "blue"})

plt.show()