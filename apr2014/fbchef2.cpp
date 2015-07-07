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
#include <queue>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define MARKER -1
using namespace std;

const int MOD = 1000000007;
const double pi = 3.141592653589793;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<string> vs;


const int n_max = 100000+5;
int w[n_max];
int w2[n_max];
int q[n_max][3];
int e[n_max][2];
int dfn[n_max][2];
int _n[n_max];
int isone[n_max];
int dfn_no = 0;
vector<int> adj[n_max];
int visited[n_max];
int bit[n_max];
int qu[n_max * 2];
int read(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += bit[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val) {
	while (idx < n_max) {
		bit[idx] += val;
		idx += (idx & -idx);
	}
}
int set_dfn(int node) {
	if (!visited[node]) {
		visited[node] = 1;
		dfn[node][0] = dfn_no;
		for (int i = 0; i < adj[node].size(); i++) {
			if (!visited[adj[node][i]]) set_dfn(adj[node][i]);
		}
		dfn_no++;
		dfn[node][1] = dfn_no;
		_n[dfn_no] = node;
		
	}
}
int main (int argc, char const *argv[])
{
	int N, Q, count, v;
	double tt = clock();
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &w[i]);
	for (int i = 0; i < N-1; i++) scanf("%d%d", &e[i][0], &e[i][1]);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &q[i][0]);
		if (q[i][0] == 1) scanf("%d%d", &q[i][1], &q[i][2]);
		else scanf("%d", &q[i][1]);
	}
	for (int i = 0; i < N-1; i++) {
		adj[e[i][0]].push_back(e[i][1]);
		adj[e[i][1]].push_back(e[i][0]);
	}
	memset(visited, 0, sizeof(visited));
	memset(isone, 0, sizeof(isone));
	memset(bit, 0, sizeof(bit));
	set_dfn(1);
	for (int i = 1; i <= N; i++) w2[i] = w[_n[i]]; 
	
	//for (int i = 1; i <= N; i++) cout << dfn[i][1] << " ";
	//cout << endl;
	//for (int i = 1; i <= N; i++) cout << _n[i] << " ";
	//cout << endl;
	for (int i = 0; i < Q; i++) {
		if (q[i][0] == 1) {
			memset(qu, 0, sizeof(qu));
			int push = 0, pop = 0;
			//cout << "bomb query" << endl;
			cout << q[i][0] << " " << q[i][1] << " " << q[i][2] << endl;
			//for(int j = 1; j <= N; j++) cout << w[j] << " ";
			//cout << endl;
			//queue<int> qu;
			memset(visited, 0, sizeof(visited));
			qu[push++] = q[i][1];
			visited[q[i][1]] = 1;
			qu[push++] = MARKER;
			int wt = q[i][2];
			while (wt && push != pop) {
				v = qu[pop++];
				//cout << "v = " << v << endl;
				if (v != MARKER) {
					w[v] -= wt;
					//if (w[v] <= 0) w[v] = 0;
					if (w[v] <= 0 && (w[v] + wt) > 0) {
						update(dfn[v][1], 1);
					}
					for (int j = 0; j < adj[v].size(); j++) {
						if (!visited[adj[v][j]]) {
							qu[push++] = adj[v][j];
							visited[adj[v][j]] = 1;
						}
					}
				}
				else {
					wt = wt>>1;
					qu[push] = MARKER;
					if(qu[push-1] == MARKER) break;
					push++;
					//cout << "q[i][2] = " << q[i][2] << endl;
				}
			}
			for (int j = 1; j <= N; j++) cout << j <<" ("<<w[_n[dfn[j][1]]] << "," << read(dfn[j][1]) - read(dfn[j][1]-1) << ") " << endl;
			//cout << endl;
			//cout << "bomb query result" << endl;
			//for(int j = 1; j <= N; j++) cout << w[j] << " ";
			//cout << endl;
		}
		else {
			v = q[i][1];
			count = read(dfn[v][1]) - read(dfn[v][0]);
			//cout << "eco query " << q[i][0] << " " << q[i][1] << endl;
			//cout << "A = " << q[i][1] << endl;
			//cout << "dfns : " << dfn[q[i][1]][0] << " " << dfn[q[i][1]][1] << endl;
			printf("%d\n", count);
		}
	}
	cout << "total time taken : " << (clock() -tt) / CLOCKS_PER_SEC << endl;  
	return 0;
}