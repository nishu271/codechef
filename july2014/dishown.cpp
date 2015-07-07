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

const int n_max = 10000+4;
const int s_max = 1000000+6;
int s[n_max], a[n_max], id[n_max], q[n_max][3];

int _find(int x) {
	if (x != id[x]) id[x] = _find(id[x]);
	return id[x]; 
}

void _union(int x, int y) {
	int id_x = _find(x);
	int id_y = _find(y);
	if (a[id_x] > a[id_y]) id[id_y] = id_x;
	else if (a[id_x] < a[id_y]) id[id_x] = id_y;
}
int main (int argc, char const *argv[])
{
	/* code */
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(id, 0, sizeof(id));
		memset(a, 0, sizeof(a));
		memset(q, 0, sizeof(q));
	
		int N, Q;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
		scanf("%d", &Q);
		for (int i = 1; i <= Q; i++) {
			scanf("%d", &q[i][0]);
			if (q[i][0]) {
				scanf("%d", &q[i][1]);
			}
			else {
				scanf("%d %d" , &q[i][1], &q[i][2]);
			}
		}
		for (int i = 1; i <= N; i++) id[i] = i;
		for (int i = 1; i <= Q; i++) {
			if (q[i][0]) {
				printf("%d\n", _find(q[i][1]));
			}
			else {
				if (_find(q[i][1]) == _find(q[i][2])) printf("Invalid query!\n");
				else _union(q[i][1], q[i][2]);
			}
		}
	}
		return 0;
}