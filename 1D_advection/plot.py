import numpy as np
import matplotlib.pyplot as plt

m=[]
with open("1D_advection.txt",'r') as file:
    for line in file:
        q=[float(word) for word in line.split()]
        m.append(q)

matrix=np.array(m)

fig = plt.figure()

for i in range(0,matrix.shape[0]):
    plt.plot(matrix[i,:])
    
plt.xlabel("x")
plt.ylabel("t")
plt.title("1D-Advection")
#plt.show()

fig.savefig("1D_advection.png")