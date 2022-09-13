import matplotlib.pyplot as plt
import numpy as np
def func(x):
    return 1-(1-np.exp(-10))*x-np.exp(-10*x)
def plotting(n):
    with open(f"problem9_v{n}.txt") as f:
        v=[float(x) for x in f.readlines()[0].split()]
    with open(f"problem9_x{n}.txt") as f:
        x=[float(x) for x in f.readlines()[0].split()]
    plt.plot(x,v,label=f"{n} steps")
    #plt.axis("equal")
plotting(10)
plotting(100)
plotting(1000)
plt.xlabel("x")
plt.ylabel("v")
plt.title("Task 7b")
plt.plot(np.linspace(0,1,1000000),func(np.array(np.linspace(0,1,1000000))),label=f"u(x)")
plt.legend()
plt.savefig("7b.pdf")
plt.show()
