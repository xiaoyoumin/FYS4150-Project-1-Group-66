import matplotlib.pyplot as plt
import numpy as np

file_u = open('problem2_u.txt')
for values in file_u:
    u = np.array(values)

file_x = open('problem2_x.txt')
for values in file_x:
    x = np.array(values)

print('x')
print(x)