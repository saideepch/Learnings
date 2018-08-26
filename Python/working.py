import numpy as np

a1 = np.arange(50)
a1.shape = (2,5,5)
print(a1)

print('Sum axis 0')
print(a1.sum(axis=0))

print('Sum axis 1')
print(a1.sum(axis=1))

print('Sum axis 2')
print(a1.sum(axis=2))

#See np.append, insert, delete and affect of axis