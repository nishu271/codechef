N = int(raw_input())

while N:
	N -= 1
	x, y = map(int, raw_input().split())
	lx, ly = [], []
	while x:
		lx.append(x)
		x /= 2
	while y:
		ly.append(y)
		y /= 2
	count = -1
	#print lx, ly
	count_max = -min(len(lx), len(ly))
	#print count_max
	while 1:
		if count < count_max:
			v = -(count+1)
			break
		if (lx[count] != ly[count]):
			v = -(count+1)
	#		print v
			break
		count -= 1
	#print v
	print (len(lx) - v + len(ly) - v)
	
