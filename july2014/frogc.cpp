
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int n_max = 100000 + 5;
const int k_max = 1000000000+5;

struct frog{
	int x;
	int i;
}f[n_max];

typedef struct frog frog_t;

int id[n_max];

bool comp(frog_t f1, frog_t f2) {
	return f1.x < f2.x;
}
int find(int i) {
	if (i != id[i]) id[i] = find(id[i]);
	        return id[i];
}

void _union(int i, int j) {
	id[find(i)] = find(j);
}

int main () {

	int n, p, k, f1, f2;
	memset(id, 0, sizeof(id));
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n_max; i++) {
		id[i] = i;
		f[i].i = i;
	}
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 1; i <= n; i++) scanf("%d", &f[i].x);
	sort(f+1, f+(n+1), comp);
	//for (int i = 1; i <= n; i++) printf("%d ", f[i].x);
	//printf("\n");
	//for (int i = 1; i <= n; i++) printf("%d ", f[i].i);
	//printf("\n");
	for (int i = 2; i <= n; i++) if (f[i].x - f[i-1].x <= k) _union(f[i].i, f[i-1].i);
	for (int i = 0; i < p; i++) {
		scanf("%d %d", &f1, &f2);
		if (find(f1) == find(f2)) printf("Yes\n");
		else printf("No\n");
	}

}
