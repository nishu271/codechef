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

const int k_max = 505;
pair<int, int> k[k_max], p[k_max]; 
int main (int argc, char const *argv[])
{
	int T, n, kk, pp, x, y;
	scanf("%d", &T);
	while(T--) {
		memset(k, 0, sizeof(k));
		memset(p, 0, sizeof(p));
		scanf("%d%d%d", &n, &kk, &pp);
		for(int i = 0; i < kk; i++) {
			scanf("%d%d", &k[i].first, &k[i].second);
		}
		for (int i = 0; i < pp; i++) {
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		sort(k, &k[kk]);
		sort(p, &p[pp]);
		/*for(int i = 0; i < kk; i++) {
			printf("%d %d\n", k[i].first, k[i].second);
		}
		for (int i = 0; i < pp; i++) {
			printf("%d %d\n", p[i].first, p[i].second);
		}*/
		int done = 1;
		int i = 0, j = 0;
		for (; i < kk && j < pp && done; i++) {
			if (p[j].second == k[i].second) j++;
			else if (j && j == pp-1 && p[j].second < p[j-1].second) {
				int lim = p[j-1].second;
				done = 0;
				while(k[i % kk].second != lim) {
					if(k[i % kk].second == p[j].second) {
						done = 1;
						j++;
						break;
					}
					i++;
				}
			}
		}
		if (j == pp) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}