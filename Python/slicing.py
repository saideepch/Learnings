import numpy as np

#1-D
list1 = [0,1,2,3,4,5]
array1 = np.array(list1)

print(array1[0:2])

#2-D
list2 = [[0,1,2,3,4], \
		 [5,6,7,8,9], \
		 [10,11,12,13,14]]

array2 = np.array(list2)
print(array2[1:,2:])	#Separator is comma, not colon. Format: [row,column]