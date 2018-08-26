import csv
import os

cwd = os.path.dirname(__file__)
# print (cwd)
# print (os.path.join(cwd,'contacts.csv'))

with open(os.path.join(cwd,'contacts.csv'),'r') as ofile, \
	 open(os.path.join(cwd,'contacts_out.csv'),'w',newline='') as wfile:	#newline='' to prevent newline in contacts_out
	
	readCSV = csv.reader(ofile, delimiter=',')
	writeCSV = csv.writer(wfile, delimiter=',')

	# print (type(readCSV))

	for row in readCSV:
		row[1] = '9' + row[1]
		print(row)
		writeCSV.writerow(row)

# Should use below to be sure for IO errors	:	
# try:
    # with open('a', 'w') as a, open('b', 'w') as b:
        # do_something()
# except IOError as e:
    # print 'Operation failed: %s' % e.strerror