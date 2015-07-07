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

const int n_max = 100000000+5;
vector<long long> inv_primes;
int check_pow_2(long long x) {
	while (x>=2) {
		if (x&1) return 0;
		x /= 2;
	}
	return 1;
}
int check_prime(vector<long long> primes, long long x) {
	if (x == 1) return 1;
 	int is_prime = 1;
	for (int i = 0; primes[i] <= sqrt(x); i++) {
		if (x%primes[i] == 0) {
			is_prime = 0;
			break;
		}
	}
	return is_prime;
}
int main (int argc, char const *argv[])
{
	/* code */
	long long x, is_prime;
	vector<long long> primes;
	primes.push_back(2);
	primes.push_back(3);
	for (int i = 6; i < sqrt(n_max); i+= 6) {
		x = i-1;
		is_prime = 1;
		for (int j = 0; primes[j] <= sqrt(x); j++) {
			if (x%primes[j] == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) primes.push_back(x);
		x = i+1;
		is_prime = 1;
		for (int j = 0; primes[j] <= sqrt(x); j++) {
			if (x%primes[j] == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) primes.push_back(x);
	}
	x=4;
	inv_primes.push_back(2);
	while (x <= n_max) {
		if (!check_prime(primes, x-1) && check_prime(primes, x+1)) {
			inv_primes.push_back(x+1);
		}
		x *= 2;
	}
	//for (int i = 0; i < inv_primes.size(); i++) {
	//	cout << inv_primes[i] << endl;
	//}
	vector<long long> lose;
	for (int i = 0; i < inv_primes.size(); i++) {
		for (int j = 1; j  < inv_primes.size(); j++) {
			lose.push_back(inv_primes[i] * inv_primes[j]);
		}
	}
	int T;
	cin >> T;
	while (T--) {
		cin >> x;
		if (find(lose.begin(), lose.end(), x) != lose.end()) {
			cout << "Tom" << endl;
			continue;
		}
		else {
			int done = 0;
			for (int i = 0; i < lose.size(); i++) {
				if (x % lose[i] == 0) {
					done = 1;
				}
			}
			if (find(inv_primes.begin(),inv_primes.end(), x) != inv_primes.end()) done = 1;
			if (done) {
				cout << "Mike" << endl;
				continue;
			}
		}
		if (x != 2 && check_prime(primes, x)) cout << "Tom" << endl;
		else {
			if (!check_prime(primes, x-1) && check_pow_2(x)) cout << "Tom" << endl;
			else cout << "Mike" << endl;
		}
	}
	return 0;
}