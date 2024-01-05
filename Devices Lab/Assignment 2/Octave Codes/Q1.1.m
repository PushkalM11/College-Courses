#To clear the text and close all windows
clc; clear; close;

#Declaring Constants
e = 1.602e-19;
kb = 1.3806e-23;

#Fermi Level
Ef = 0;

#Energy levels 
Ev = Ef - 0.3;
Ec = Ef + 0.3;

#Declaring the energy array
E = linspace(Ev , Ec);

#Fermi-Dirac Statistics
#For loop for temperature
for T = 0 : 100 : 600
	
	#Looping for each energy value
	for i = 1 : length(E)

		#Assigning probability for each energy
		F(i) = 1 / (1 + exp(((E(i) - Ef) * e) / (kb * T)));
	endfor

	#Plotting on the left graph
	subplot(1, 2, 1), plot(E, F, 'linewidth', 2.5 - (T / 400));
	hold on

endfor
hold off

#Legend for left graph
legend('0K', '100k', '200K', '300K', '400K', '500k', '600k', 'fontsize', 25);

#Title
title('Fermi-Dirac Distribution', 'fontsize', 25);

#xlabel
xlabel('Energy(in eV)', 'fontsize', 25);

#ylabel
ylabel('Probability of Occupation f(E)', 'fontsize', 25);

#Re-Declaring Constants
e = 1.602e-19;
kb = 1.38e-23;

#Changing Energy levels 
Ev = Ef; 
Ec = Ef + 0.3;

#Re-Declaring the energy array
E = linspace(Ev, Ec);

#Maxwell-Boltzmann Statistics
#For loop for temperature
for T = 0 : 100 : 600
	
	#Looping for each energy value
	for i = 1 : length(E)

		#Assigning probability for each energy
		M(i) = 1 / exp(((E(i) - Ef) * e) / (kb * T));
	endfor

	#Plotting on the left graph
	subplot(1, 2, 2), plot(E, M, 'linewidth', 2.5 - (T / 400));
	hold on

endfor
hold off

#Legend for right graph
legend('0K', '100k', '200K', '300K', '400K', '500k', '600k', 'fontsize', 30);

#Title
title('Maxwell-Boltzmann Statistics', 'fontsize', 25);

#Label for x-axis
xlabel('Energy(in eV)', 'fontsize', 25);

#Label for y-axis
ylabel('Probability of Occupation f(E)', 'fontsize', 25);