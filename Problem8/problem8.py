import matplotlib.pyplot as plt
import numpy as np
from numpy import log10 


"""
opening our  txt files from problem 2 using pythons built in 'open'
"""

file_u = open('problem2_u.txt')
for values in file_u:
    u = np.array(values)

file_x = open('problem2_x.txt')
for values in file_x:
    x = np.array(values)

#print('testing if values are copied correctly', x) #checking if values are correctly copied into the array



def abs_error(x , y, v):                   #calculates the absolute error

    log10delta = np.zeros(len(x))
    for i in range(0, len(x)):
        log10delta[i] = log10(abs(u[i] - v[i]))
        
    return log10delta

def rel_error(x, y, v):                    #calculates relative error

    log10eps = np.zeros(len(x))
    for i in range(0, len(x)):
        log10eps = log10(abs((u[i] - v[i])/u[i]))

    return log10eps