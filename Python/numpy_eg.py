import numpy as np
import matplotlib.pyplot as plt
import math
import os
cwd = os.path.dirname(__file__)

a = np.array([0, 1, 2, 3])
print(a)
print(len(a))
print(type(a))

c = np.array([[[1], [2]], [[3], [4]]])
print(c)
print(c.shape)
print(len(c))

print("np.random.rand(50) is" + str(np.random.rand(50)))

d = np.linspace(0, 1, 5, endpoint=False)
e = np.linspace(0, 1, 5)
print(d)
print(e)

f = np.empty(2)
print(f)
g = np.empty([2,2])
print(g)
h = np.empty([2,2],dtype=int)
print(h)

i = np.random.rand(5)	# uniform in [0, 1]
print(i)
j = np.random.rand(3,3)
print(j)

print(math.cos(60*math.pi/180))

k = np.zeros(100)
k = [math.cos(x*math.pi/180) for x in range(0,361)]
xaxis = [range(0,361)]
print(np.shape(k))
print(np.shape(xaxis))
# plt.plot(xaxis,np.reshape(k,(1,361)),color='blue')
# plt.show()  # Check why not working

data = np.loadtxt(os.path.join(cwd,'populations.txt'))
print(data)
year, hares, lynxes, carrots = data.T
plt.axes([0.2, 0.1, 0.5, 0.8]) 
plt.plot(year, hares, year, lynxes, year, carrots) 
plt.legend(('Hare', 'Lynx', 'Carrot'), loc=(1.05, 0.5))
plt.show()
print('slice data: ');  print(data[: ,1:])	#Note the diff betn data[: ,1:] and data[: 1:] !! ,1 will slice from second column to give sub-matrix. Also see diff betn [:,1:] and [:,1]
populations = data[: ,1:]
print(populations.mean(axis=0))
print(populations.std(axis=0)) #stand. dev.
#Which species has the highest population each year?:
print(np.argmax(populations, axis=1)) #returns 0 or 1 or 2 for hare or lynx or carrot resp. Better see o/p.

#See https://campus.datacamp.com/courses/intro-to-python-for-data-science/chapter-4-numpy?ex=11

