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

const int max_n = 100006;
long long ar[max_n], ar1[max_n], ar2[max_n];

void print_array(long long *a, int len) {
	for (int i = 0; i < len; i++) printf("%lld ", a[i]);
	printf("\n");
}
int main (int argc, char const *argv[])
{
	int N,K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%lld", &ar[i]);
	long long mx=ar[0], mi=ar[0];
	for (int i = 0; i < N; i++) {
		mx = (mx > ar[i]) ? mx : ar[i];
		mi = (mi < ar[i]) ? mi : ar[i];
	}
	
	for (int i = 0; i < N; i++) ar1[i] = mx - ar[i];
	for (int i = 0; i < N; i++) ar2[i] = (mx-mi) - ar1[i];
	
	if (K == 0) print_array(ar, N);
	else if (K & 1) print_array(ar1, N);
	else print_array(ar2, N);
	
	return 0;
}