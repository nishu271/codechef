n, m = map(int, raw_input().split())
ar = map(int, list(raw_input().split()[0]))
ar_list = [[abs(i - a) for a in ar] for i in range(10)]
#print ar_list
s = []
for i in range(10):
	s.append([])
	for j in range(len(ar_list[i])):
		if j == 0:
			#print s[i]
			s[i].append(ar_list[i][j])
		else :
			s[i].append(s[i][-1] + ar_list[i][j])
#print s
while m:
	m -= 1
	x = int(raw_input())
	if x > 1 : 
		print s[ar[x-1]][x-2]
	else : 
		print 0