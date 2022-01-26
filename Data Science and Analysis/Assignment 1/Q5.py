import csv
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

data = []
num_categories = 16

with open ("exoplanet.eu_catalog.csv", 'r') as csvfile:
	csvreader = csv.reader(csvfile)

	fields = next(csvreader)
	index = fields.index('eccentricity')

	for row in csvreader:
		if (row[index] != '') and (row[index] != '0.0'):
			data.append(float(row[index]))

plt.hist(data, bins = num_categories)
plt.title("Histogram Plot before Box-Transformation")
plt.xlabel("Eccentricity e")
plt.ylabel("Count of exoplanets")
plt.show()

new_data, tmp = stats.boxcox(data)

plt.hist(new_data, bins = num_categories)
plt.title("Histogram Plot after Box-Transformation")
plt.xlabel("Eccentricity e")
plt.ylabel("Count of exoplanets")
plt.show()