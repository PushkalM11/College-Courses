import numpy as np
import math

p1 = float(input(('Enter Input Vector p1 : ')))
q1 = float(input('Enter Input Vector q1 : '))

# comparing against p2,q2

p2 = float(input(('Enter Input Vector p2 : ')))
q2 = float(input('Enter Input Vector q2 : '))

n1 = np.linalg.norm(np.matrix([p1,q1]))
n2 = np.linalg.norm(np.matrix([p2,q2]))

p2 = p2*n1/n2
q2 = q2*n1/n2

ivec = np.matrix([[p1],[q1]])

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
theta = 0

for i in range(8):
    if q1>q2:
        ftheta = theta - angles[i]
        fvec = clk(ivec, angles[i])
        print(fvec,angles[i])
        theta = ftheta
        q1 = fvec[1]
    else:
        ftheta = theta + angles[i]
        fvec = aclk(ivec, angles[i])
        print(fvec,-1*angles[i])
        theta = ftheta
        q1 = fvec[1]

    ivec = fvec

phase = -1*theta

print(fvec, phase)
