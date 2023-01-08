# from numpy import *
#
# # Length of links in cm
# a1 = 20
# a2 = 20
#
# # Desired Position of End effector
# px = 30
# py = 0
#
# phi = 0
# phi = deg2rad(phi)
#
# # Equations for Inverse kinematics
# wx = px - a3*cos(phi)
# wy = py - a3*sin(phi)
#
# delta = wx**2 + wy**2
# c2 = ( delta -a1**2 -a2**2)/(2*a1*a2)
# s2 = sqrt(1-c2**2)  # elbow down
# theta_2 = arctan2(s2, c2)
#
# s1 = ((a1+a2*c2)*wy - a2*s2*wx)/delta
# c1 = ((a1+a2*c2)*wx + a2*s2*wy)/delta
# theta_1 = arctan2(s1,c1)
# theta_3 = phi-theta_1-theta_2
#
# print('theta_1: ', rad2deg(theta_1))
# print('theta_2: ', rad2deg(theta_2))
# print('theta_3: ', rad2deg(theta_3))

from numpy import *

a1 = 0  # length of link a1 in cm
a2 = 20  # length of link a2 in cm
a3 = 0  # length of link a3 in cm
a4 = 20  # length of link a4 in cm

# Desired Position of End effector
x = 35
y = -10

# Equations for Inverse kinematics
r1 = sqrt(x**2+y**2)  # eqn 1
phi_1 = arccos((a4**2-a2**2-r1**2)/(-2*a2*r1))  # eqn 2
phi_2 = arctan2(y, x)  # eqn 3
theta_1 = rad2deg(phi_2-phi_1)  # eqn 4 converted to degrees
print(phi_1-phi_2)
print((phi_1-phi_2)*180/3.1415)
print((phi_1-phi_2)*3.1415/180)
phi_3 = arccos((r1**2-a2**2-a4**2)/(-2*a2*a4))
theta_2 = 180-rad2deg(phi_3)

print('theta one: ', theta_1)
print('theta two: ', theta_2)