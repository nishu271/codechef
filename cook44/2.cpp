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

int main (int argc, char const *argv[])
{
	int N;
	cin >>N;
	int sum = 0, x;
	int v = (N * (N+1))/ 2;
	for (int i = 0; i < N; i++) {
		cin >> x;
		sum += x;
	}
	if (v == sum) cout << "YES" <<endl;
	else cout << "NO" << endl;
	return 0;
}