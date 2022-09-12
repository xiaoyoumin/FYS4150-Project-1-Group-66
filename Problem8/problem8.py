import matplotlib.pyplot as plt
import numpy as np
from numpy import log10 


"""
opening our  txt files from problem 2 using pythons built in 'open'
"""

file_u = open('problem2_u.txt')
for values in file_u:
    numbers = values.split(" ")
    u = np.array(numbers)

file_x = open('problem2_x.txt')
for values in file_x:
    numbers = values.split(" ")
    x = np.array(numbers)
print(x[3])


#taking in values from task 7
"""
file_v = open('problem7_v.txt')           
for values in file_x:
    numbers = values.split(" ")
    v = np.array(numbers)
print(x[3])
"""

#print('testing if values are copied correctly', x) #checking if values are correctly copied into the array



def abs_error(u, v):                    #calculates the absolute error

    log10delta = np.zeros(len(u))
    for i in range(0, len(u)):
        log10delta = log10(abs(u[i] - v[i]))
        
    return log10delta


def rel_error(u, v):                    #calculates relative error

    log10eps = np.zeros(len(u))
    for i in range(0, len(u)):
        log10eps = log10(abs((u[i] - v[i])/u[i]))

    return log10eps

real = rel_error(u, x)
absolute_vodka = abs_error(u, x)

fig, axs = plt.subplots(2)
fig.suptitle('Vertically stacked subplots')
axs[0].set_title("main")
axs[0].plot(x, absolute_vodka)
fig.suptitle('Vertically stacked subplots')
axs[1].set_title("main")
axs[1].plot(x, real)
