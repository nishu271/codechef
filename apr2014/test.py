import random
"""
with open("test.txt", "w") as f:
	T = 3
	N = 100000
	Q = 30
	f.write(str(T)+ "\n")
	for i in range(T):
		f.write(str(N) + " " + str(Q) + "\n")
		f.write(" ".join([str(random.randint(- 10 ** 9, 10**9)) for i in range(N)]) + "\n")
		f.write("\n".join([str(random.randint(1, 100)) for i in range(Q)]) + "\n")
"""
with open("test100.txt", "w") as f:
	N = 100
	Q = 40
	a = range(1, N+1)
	b = [a.pop(0)]
	f.write(str(N)+ "\n")
	for i in range(N):
		f.write(str(random.randint(10**2, 10**3)) + "\n")
	for i in range(N-1):
		x = a.pop(random.randint(0, len(a)-1))
		y = b[random.randint(0,len(b)-1)]
		f.write(str(x) + " " + str(y) + "\n")
		b.append(x)
	f.write(str(Q)+ "\n")
	for i in range(Q):
		t = random.randint(1,2)
		if t == 1:
			f.write(str(t) + " " + str(random.randint(1, N)) + " " + str(random.randint(1, 10**3)) + "\n")
		else :
			f.write(str(t) + " " + str(random.randint(1,N)) + "\n")