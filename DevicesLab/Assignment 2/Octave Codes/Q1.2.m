#To clear the text and close all windows
clc; clear; close;

#Declaring the test array
test = linspace(0, 10);

#Loop for Fermi-Dirac Statistics 
for i = 1 : length(test)

    #From Fermi-Dirac Statistics 
    f(i) = 1 / (1 + exp(test(i)));

endfor

#Plot for Fermi-Dirac Statistics
plot(test, f, 'linewidth', 2)

hold on

#Loop for Maxwell-Boltzmann Statistics
for i = 1 : length(test)

    #From Maxwell-Boltzmann Statistics
    f(i) = exp((-1 * test(i)));

endfor

#Plot for Maxwell-Boltzmann Statistics
plot(test, f, 'linewidth', 2)

hold off

#Legend
legend('Fermi-Dirac', 'Maxwell-Boltzmann', 'fontsize', 25)

#Title
title('Fermi-Dirac Statistics reducing to Maxwell-Boltzmann Statistics', 'fontsize', 25)

#Label for x-axis
xlabel('(E-Ef) / (kb*T)', 'fontsize', 25);

#Label for y-axis
ylabel('Probability of Occupation f(E)', 'fontsize', 25);