data = [0.8920, 0.881, 0.8913, 0.9837, 0.8958]
error = [0.00044, 0.009, 0.00032, 0.00048, 0.00045]

weighted_mean = 0
uncertainty_in_mean = 0

for i in range(5):
	weighted_mean += (data[i] / pow(error[i], 2))
	uncertainty_in_mean += (1 / pow(error[i], 2))
	
weighted_mean /= uncertainty_in_mean
uncertainty_in_mean = 1 / uncertainty_in_mean

print(f'The weighted mean of lifetime of K meson is: {weighted_mean} in 10^(-10)s')
print(f'The uncertainty in mean of lifetime is: {pow(uncertainty_in_mean, 0.5)}')