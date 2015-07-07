import random
f = open("test", "w")
s = ""
n = 100000
for i in range(n):
	s += random.choice(['A','B','C'])
f.write(s+"\n")
f.close()