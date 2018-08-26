import random
import time

#alphabet = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
lower = "abcdefghijklmnopqrstuvwxyz"
numbers = "0123456789"
symbol = "`~!@#$%^&*()_+-=[]{}\|;:\'\"<>,.?/"

pw_length = 8
mypw = ""

while (1):
	mypw = ""
	
	for i in range(5):
		next_index = random.randrange(len(lower))
		mypw = mypw + lower[next_index]
		
	next_index = random.randrange(len(upper))
	mypw = mypw + upper[next_index]
		
	next_index = random.randrange(len(numbers))
	mypw = mypw + numbers[next_index]
		
	next_index = random.randrange(len(symbol))
	mypw = mypw + symbol[next_index]

	#''.join(random.sample(mypw,len(mypw)) #strangely giving parse errors

	#M2:
	
	final_pw = ""; temp_list = ""
	
	temp_list = list (mypw)
	random.shuffle (temp_list)
	final_pw = ''.join(temp_list)

	print (final_pw)
	time.sleep (1)