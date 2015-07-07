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

const int MOD = 1000000009;
const double pi = 3.141592653589793;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<string> vs;

const int n_max = 100000+5;
const int m_max = 100+1;
int num_subsets[n_max][m_max];
int ar[3][n_max];
int n[3];
int q[3];
int m[3][31];
int res[m_max];
int mmod[m_max][m_max*2];
int main (int argc, char const *argv[])
{
	int T,N,Q,M;
	double tt0 = clock(),tt;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &n[i], &q[i]);
		for (int j = 0;j < n[i]; j++) {
			scanf("%d", &ar[i][j]);
		}
		for (int j = 0;j < q[i]; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	for (int i = 1; i < m_max; i++) {
		for (int j = 0; j < m_max * 2;j++) {
			mmod[i][j] = j % i;
		}
	}
	//cout << "Time taken in input " << (clock() - t)/CLOCKS_PER_SEC << " secs" << endl;
	for (int t = 0; t < T; t++) {
		int k;
		N = n[t];
		memset(res, 0, sizeof(res));
		for(int qq = 0; qq < q[t]; qq++) {
			M = m[t][qq];
			if (!res[M]) {
				//tt = clock();
				memset(num_subsets, 0, sizeof(num_subsets));
				//cout << "time in memset " << (clock() - tt) / CLOCKS_PER_SEC << endl;
				k = (ar[t][0] % M + M) % M;
				num_subsets[0][k] = 1;
				//tt = clock();
				for (int i = 1; i < N; i++) {
					//k = (ar[t][i] % M + M) % M;
					k = ar[t][i] % M;
					if (k < 0) k += M;
				//cout << k << " " << ar[i] << endl;
					for (int j = 0; j < M; j++) {
						num_subsets[i][j] = (num_subsets[i-1][j] + num_subsets[i-1][mmod[M][M - k + j]] + (j == k)) % MOD;
					}
				}
				//cout << "time in loop " << (clock() - tt) / CLOCKS_PER_SEC << endl;
				res[M] = num_subsets[N-1][0] + 1;
			}
			/*for (int i = 0; i < N; i++) {
				k = (ar[i] % M + M) % M;
				cout << k << " " << ar[i] << " ## ";
				for (int j = 0; j < M; j++) {
					cout << num_subsets[i][j] << " ";
				}
				cout << endl;
			}*/
			printf("%d\n", res[M]);
			//cout << "Time taken in T = " << t << ", Q = "<< qq << ",M = " << M<< " " << (clock() - t)/CLOCKS_PER_SEC << " secs" << endl;
		}
	}
	//cout << "Time taken" << (clock() - tt0)/CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}