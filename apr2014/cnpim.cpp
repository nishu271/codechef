#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,s,n) for(int i = (s); i < (n); i++)

using namespace std;

const int MOD = 1000000007;
const double pi = 3.141592653589793;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<string> vs;

const int _max = 2500;
const int factors_max = _max/2 * _max/2 + 5;
const int primes_max = 240000;
int factors[factors_max];
int primes[primes_max];
int main (int argc, char const *argv[])
{
	unsigned int T,N,x,is_prime;
	double t = clock();
	/*int c = 0;
	primes[c++] = 2;
	primes[c++] = 3;
	for (int i = 6; i < factors_max; i++) {
		x = i-1;
		is_prime = 1;
		for (int j = 0; primes[j] <= sqrt(x); j++) {
			if (x%primes[j] == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) primes[c++] = x;
		x = i+1;
		is_prime = 1;
		for (int j = 0; primes[j] <= sqrt(x); j++) {
			if (x%primes[j] == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) primes[c++] = x;
	}
	cout << "c = " << c<<" time_taken " << (clock() - t)/CLOCKS_PER_SEC << " secs" <<endl;
	*/
	scanf("%d", &T);
	unsigned int m,ways;
	while (T--) {
		scanf("%d", &N);	
		ways = 0;
		for (int i = 1; i < N; i++) {
			m = (N-i) * i - 1;
			for(int j = 1; j <= sqrt(m); j++) {
				if(m/j >= j) ways += 2 * (m/j - (j-1)) - 1;
			}
		}	
		printf("%u\n",ways);
	}
	//cout << "time_taken " << (clock() - t)/CLOCKS_PER_SEC << " secs" <<endl;
	return 0;
}