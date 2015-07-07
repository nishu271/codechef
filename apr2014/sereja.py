import random
def f(A,i,S,sum_ar,l):
	if A[i] > S: return S
	else :
		if i == 0:
			if S >= sum_ar[-1]: return S-sum_ar[-1]
			for ix in range(i,l):
				if S < sum_ar[ix]:
					return (S - sum_ar[ix-1])
				
		else :	
			if S >= sum_ar[-1] - sum_ar[i-1]: return S-(sum_ar[-1] - sum_ar[i-1])
			for ix in range(i, l):
				if S < sum_ar[ix] - sum_ar[i-1]:
					return S - (sum_ar[ix-1] - sum_ar[i-1]) 
			
def compute_score(A, S, k, p, N):
	A = [A[i-1] for i in p]
	sum_ar = range(N)
	for i in range(len(A)):
		if i ==  0: sum_ar[i] = A[i]
		else : sum_ar[i] = A[i] + sum_ar[i-1]
	score = float(sum([f(A,i,S,sum_ar,N)for i in range(k)])) / k
	return score


T = int(raw_input())
while T:
	T -= 1
	N, k, S = map(int, raw_input().split())
	A = map(int, raw_input().split())
	a = [i for i in range(N) if A[i] <= S]
	#print "a", a
	a_c = [A[i] for i in a]
	#print "a_c", a_c
	d = {}
	for i in range(len(a)):
		if not d.has_key(A[a[i]]):
			d[A[a[i]]] = [a[i]]
		else:
			d[A[a[i]]].append(a[i])
	#print d
	a_c.sort()
	#aa_c = [i for i in a_c]
	#aa_c.reverse()
	#if len(aa_c) > k:
	#aa_c = aa_c[0:k]
	#aa_c.reverse()
	#a_c.reverse()
	b = []
	for i in a_c:
		b.append(d[i][0])
		d[i].pop(0)
	#print b
	ll = range(N)
	if len(b) > k:
		bb = b[:k]
		cc = b[k:]
		cc.reverse()
		bb.extend(cc)
		b = bb
	for i in b:
		ll.remove(i)
	b.extend(ll)
	#print b
	p = [1 + i for i in b]	
	#p = range(1, len(A)+1)
	#p.reverse()
	#t = range(1, len(A)+1)
	#ll = [[compute_score(A, S, k, x, N), x] for x in [t,p]]
	#print ll
	#ll.sort()
	#print ll
	#random.shuffle(p)
	print " ".join(map(str, p))
	