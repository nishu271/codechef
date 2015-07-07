#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}
int main () {
	int T;
	cin >> T;
	while(T--) {
		long long n,m;
		cin >> n >> m;
		if (n & 1 && m & 1) {
			long long a = (n/2 + 1) * (m/2)  + (m/2 + 1) * (n/2); 
			long long b = n * m;
			long long gcd_ab = gcd(a,b);
			cout << a/gcd_ab << "/" << b/gcd_ab << endl;
		}
		else cout << "1/2" << endl;
	}
}
