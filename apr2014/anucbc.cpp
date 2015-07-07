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

const int n_max = 100000+5;
const int m_max = 100+1;
const int MOD = 1000000009;
int num_subsets[n_max][m_max][2];
int ar[n_max];
int main (int argc, char const *argv[])
{
	int T,N,Q;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &Q)
		for (int i = 0; i < N; i++) {
			scanf("%d", &ar[i]);
		}
		memset(num_subsets, 0, sizeof(num_subsets));
		for (int i = 1; i < m_max; i++) {
			num_subsets[0][i][0] = (abs(ar[0]) % i == 0);
			num_subsets[0][i][1] = (abs(ar[0]) % i == 0);
		}
		int k;
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < m_max; j++) {
				k = ar[i] % j;
				if (k < 0) {
					num_subsets[i][j][1] = (num_subsets[i-1][j][1] + num_subsets[i-1][-k][1] + num_subsets[i-1][j+k][0]) % MOD; 
				}
				else num_subsets[i][j] = (num_subsets[i-1][j] + num_subsets[i-1][j-k]) % MOD;
			}
		}
		for (int i = 0; i < Q; i++) {
			scanf("%d", &M);
			prints("%d\n", num_subsets[N-1][M]);
		}
	
	}
	return 0;
}