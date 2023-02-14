import numpy as np
import matplotlib.pyplot as plt

m=[]
with open("1d-advection2.txt",'r') as file:
    for line in file:
        q=[float(word) for word in line.split()]
        m.append(q)

with open("x-axis.txt",'r') as file:
    for line in file:
        x=[float(word) for word in line.split()]

with open("t-axis.txt",'r') as file:
    for line in file:
        t=[float(word) for word in line.split()]

matrix=np.array(m)

T=np.array(t)
X=np.array(x)

fig = plt.figure()

for i in range(0,matrix.shape[0]):
   plt.plot(X[:],matrix[i,:])
    
plt.xlabel("x")
plt.ylabel("Concentration")
plt.xlim([x[0],x[-1]])
plt.ylim([min(map(min, matrix)),max(map(max, matrix))])
plt.title("1D-Advection")
fig.savefig("1d-advection2.png")