primes = [x for x in range(2,1251) if sum((1 for i in range(2,x) if x % i != 0)) == x - 2]
T = int(raw_input())

while T:
	T -= 1
	val = sum(map(int, raw_input().split()))
	for i in primes:
		if val < i:
			print i - val
			break
