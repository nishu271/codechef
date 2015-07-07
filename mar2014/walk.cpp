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

const int n_max = 100001;
int main (int argc, char const *argv[])
{
	int T, N;
	int ar[n_max];
	cin >> T;
	while (T--) {
		//cout << T << endl;
		memset(ar, 0, sizeof(ar));
		cin >> N;
		for (int i = 0; i < N; i++) {
			scanf("%d", &ar[i]);
		}
		int v = ar[0];
		int t = v;
		if (N==1) {
			printf("%d\n", v);
			continue;
		}
		
		for (int i = 1; i < N; i++) {
			v--;
			if (ar[i] > v) {
				t += ar[i] - v;
				v = ar[i];
			}
		}
		printf("%d\n", t);
	}
	return 0;
}