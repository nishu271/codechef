#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

const long long MOD = 1000000007;
const int n_max = 100000+5;
int visited[n_max];
long long comps[n_max];
int ar[n_max];

long long a_pow_b_mod_p(long long a, long long b, long long p) {
	long long r = 1;
	while (b) {
		if (b&1) r = (r * a) % p;
		a  = (a * a) % p;
		b = b >> 1;
	}
	return r;
}
long long inverse_mod_p(long long a, long long p) {
	return a_pow_b_mod_p(a, p-1, p);
}
long long gcd(long long a, long long b) {
	long long x = a, y = b;
	if (a < b) {
		y = a;
		x = b;
	}
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}
int main () {
	int T;
	scanf("%d", &T);
	for (int j = 0; j < T; j++) {
		memset(visited, 0, sizeof(visited));
		memset(comps, 0, sizeof(comps));
		memset(ar, 0, sizeof(ar));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ar[i]);
		}
		int comp = 0;
		for (int i = 1; i <= n; i++) {
			long long count = 0;
			if (!visited[i]) {
				int x = i;
				while(!visited[x]) {
					visited[x] = 1;
					x = ar[x];
					count++;
				}
				comps[comp++] = count;
			}
		}
		map<int, int> d;
		for (int i = 0; i < comp; i++) {
			if (comps[i] > 1 && d[i] 
		}
		//cout << comp << endl;
		long long _gcd;
		for (int i = 0; i < comp && comp > 1; i++) if (comps[i] > 1)  {_gcd = comps[i]; break;}
		//cout << _gcd << endl;
	    long long prod = 1;
		for (int i = 0; i < comp && comp > 1; i++) {
			//cout << "comp[" <<i<<"]= " << comps[i] << endl; 
			if (comps[i] > 1) _gcd = gcd(_gcd, comps[i]);
		}
		//cout << _gcd << endl;
		for (int i = 0; i < comp && comp > 1; i++) if (comps[i] > 1) {comps[i] /= _gcd; break;}
		for (int i = 0; i < comp; i++) {
			//cout << "comp[" <<i<<"]= " << comps[i] << endl; 
			prod = (prod * comps[i]) % MOD;
		}
		//cout << "c"<<inverse_mod_p(_gcd, MOD) << endl;
		//long long lcm = (prod * inverse_mod_p(_gcd, MOD)) % MOD;
		//cout << gcd(100, 10220) << endl;
		printf("%lld\n", prod);
	}
}
