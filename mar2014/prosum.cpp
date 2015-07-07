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

const int n_max = 100000+3;
int main (int argc, char const *argv[])
{
	long long int T, N;
	int ar[n_max], tmp[n_max], tmp2[n_max];
	cin >> T;
	while (T--) {
		cin >> N;
		memset(ar, 0, sizeof(ar));
		memset(tmp, 0, sizeof(tmp));
		memset(tmp2, 0, sizeof(tmp2));
		for (int i = 0; i < N; i++) scanf("%d", &ar[i]);
		if (ar[0] <= 2) tmp[0] = 1;
		else tmp[0] = 0;
		for (int i = 1; i < N; i++) {
			if (ar[i] <= 2) {
				tmp[i] = tmp[i-1] + 1;
			}
			else {
				tmp[i] = tmp[i-1];
			}
		}
		if (ar[0] <= 1) tmp2[0] = 1;
		else tmp2[0] = 0;
		for (int i = 1; i < N; i++) {
			if (ar[i] <= 1) {
				tmp2[i] = tmp2[i-1] + 1;
			}
			else {
				tmp2[i] = tmp2[i-1];
			}
		}
		long long int ans = 0;
		for (int i = 0; i < N; i++) {
			if (ar[i] <= 1) ans += (N - i - 1);
			else if (ar[i] == 2) ans += tmp[N-1] - tmp[i];
			else {
				ans += tmp2[N-1] - tmp2[i];
			}
		}
		printf("%lld\n", N * (N-1) / 2 - ans);
	}
	
	return 0;
}