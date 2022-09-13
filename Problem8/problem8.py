import matplotlib.pyplot as plt
import numpy as np
def func(x):
    return 1-(1-np.exp(-10))*x-np.exp(-10*x)
def plotting(n):
    with open(f"problem9_v{n}.txt") as f:
        v=[float(x) for x in f.readlines()[0].split()]
    with open(f"problem9_x{n}.txt") as f:
        x=[float(x) for x in f.readlines()[0].split()]
    v=np.array(v)[1:-1]
    x=np.array(x)[1:-1]
    axs1[int(np.log10(n)-1)].plot(x, np.abs(np.log10(np.abs(func(x)-v))))

    axs2[int(np.log10(n)-1)].plot(x, np.abs(np.log10(np.abs((func(x)-v)/func(x)))))

    axs1[int(np.log10(n)-1)].set_xlabel("x")
    axs1[int(np.log10(n)-1)].set_ylabel("asolute error")

    axs2[int(np.log10(n)-1)].set_xlabel("x")
    axs2[int(np.log10(n)-1)].set_ylabel("relative error")
    #plt.axis("equal")

fig1, axs1 = plt.subplots(4)
fig1.suptitle('8a absolute error')

fig2, axs2 = plt.subplots(4)
fig2.suptitle('8b relative error')

plotting(10)
plotting(100)
plotting(1000)
plotting(10000)
plt.show()
def maxError(n):
    with open(f"problem9_v{n}.txt") as f:
        v=[float(x) for x in f.readlines()[0].split()]
    with open(f"problem9_x{n}.txt") as f:
        x=[float(x) for x in f.readlines()[0].split()]
    v=np.array(v)[1:-1]
    x=np.array(x)[1:-1]
    return np.max(np.abs(np.log10(np.abs((func(x)-v)/func(x)))))
max=[]
x=[]
for i in range(7):
    x.append(int(eval(f"10e{i}")))
    max.append(maxError(int(eval(f"10e{i}"))))
plt.plot(x,max)
plt.title("8c max relative error")
plt.xlabel("n")
plt.ylabel("max relative error")
plt.show()