import numpy as np
import math

x0 = float(input(('Enter Input Vector x : ')))
y0 = float(input('Enter Input Vector y : '))
theta = float(input('Enter angle : '))

ivec = np.matrix([[x0],[y0]])

def clk(ivec,alpha):
    alpha = math.radians(alpha)
    mat = np.matrix([[math.cos(alpha),math.sin(alpha)], [-1*math.sin(alpha), math.cos(alpha)]])
    fvec = mat*ivec
    return fvec

def aclk(ivec,alpha):
    alpha = math.radians(alpha)
    mat = np.matrix([[math.cos(alpha),-1*math.sin(alpha)], [math.sin(alpha), math.cos(alpha)]])
    fvec = mat*ivec
    return fvec

angles = [45, 26.57, 14.04, 7.13, 3.58, 1.79, 0.895, 0.448]

for i in range(8):
    if theta>0:
        ftheta = theta - angles[i]
        fvec = clk(ivec, angles[i])
        print(theta, angles[i], ftheta, fvec)
        theta = ftheta
    else:
        ftheta = theta + angles[i]
        fvec = aclk(ivec, angles[i])
        print(theta, -1*angles[i], ftheta, fvec)
        theta = ftheta
    ivec = fvec
