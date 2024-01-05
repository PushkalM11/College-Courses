#To clear the text and close all windows
clc; clear; close;

#Declaring Constants
e = 1.602e-19
h = 6.626e-34
kb = 1.3806e-23
Eg = 1.12 * e

#Given Effective Density of States for Conduction Band
Nc = 2.8e19;

#Given Effective Density of States for Valence Band
Nv = 1.8e19;

#Declaring the temperature array
T = linspace(100, 1000, 100)

#Calculating the equivalent x-axis values for temperature
T_for_x_axis = 1000 ./ T;

#Loop to calculate the Intrinsic Carrier Concentration for each temperature element
for i = 1 : length(T)

    #As discussed in class
    Ni(i) = (Nv * Nc)^(0.5) * exp((-1 * Eg) / (2 * kb * T(i)))

endfor

#Plot for Ni vs T
#Plot 
subplot(1, 2, 1), plot(T, Ni, 'linewidth', 3)

hold on

#Label for x-axis
xlabel('Temperature(in K)', 'fontsize', 25);

#Label for y-axis
ylabel('Intrinsic Carrier Concentration', 'fontsize', 25);

#Plot for Ni vs 1000 / T
#Semilog Plot
subplot(1, 2, 2), semilogy(T_for_x_axis, Ni, 'linewidth', 3)

hold off

#Label for x-axis
xlabel("1000 / T ", 'fontsize', 25);

#Label for y-axis
ylabel("Intrinsic Carrier Concentration in Semilog scale", 'fontsize', 25);