#To clear the text and close all windows
clc; clear; close;

#Declaring Constants
e = 1.602e-19;
kb = 1.3806e-23;
m= 9.31e-31;
h=6.582e-16;

#Energy levels 
Ev = -0.6;
Ec = 0.6;

#Fermi Level
Ef = 0.04;

#Declaring the energy array
E = linspace(-1, 1);

#Temperature variable
T = 300;

#For electron density at room temperature
#Loop to calculate probability, density of states and electron density for each energy in E
for i = 1 : length(E)
  	
	#From Fermi-Dirac Statistics
  	F(i) = (1 / (1 + exp(e * (E(i) - Ef) / (kb * T)))); 

  	#Density of states
  	D(i) = (1 / (2 * pi * pi)) * ((2 * m / (h * h))^1.5) * (E(i) - Ec)^0.5;

  	#Electron Density
  	N(i) = F(i) * D(i);

endfor

#Plotting for electron density
plot(N, E, 'linewidth', 1.5)

hold on 

#For hole density
#Loop to calculate probability, density of states and hole density for each energy in E
for i = 1 : length(E)

	#From Fermi-Dirac Statistics
	#But for hole, the probability is 1 - F(i) 
  	F(i) = (1 / (1 + exp((E(i) - Ef) * e / (kb * T)))); 

  	#Density of states
  	D(i) = (1 / (2 * pi * pi)) * ((2 * m / (h * h))^1.5) * (Ev - E(i))^0.5;

  	#Hole density
  	N(i) = (1 - F(i)) * D(i);

endfor

#Plotting for hole density
plot(N, E, 'linewidth', 1.5)

hold off

#Legend for the graph
legend('Electron Density', 'Hole Density', 'fontsize', 25);

#Title
title('Energy of Carrier vs Density of Carrier',' fontsize', 30);

#Label for x-axis
xlabel('Density', 'fontsize', 25);

#Label for y-axis
ylabel('Energy(in eV)', 'fontsize', 25);