import matplotlib.pyplot as plt

with open(f"problem2.txt") as f:
    lines = f.readlines()
    x = []
    u = []
    for line in lines:
        vals = line.split("\t")
        x.append(float(vals[0]))
        u.append(float(vals[1]))

plt.plot(x,u)
plt.grid(True) 
plt.xlabel('x')
plt.ylabel('u(x)')
plt.title('u(x) = 1-(1-e^{-10})x-e^{-10x}')
plt.savefig("2.pdf")