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

const int s_max = 100005;
char s[1000005];
int main (int argc, char const *argv[])
{
	/* code */
	int ar[3];
	scanf("%s", s);
	int l = strlen(s);
	memset(ar, 0, sizeof(ar));
	long long sum= 0;
	int count = 0;
	for (int i = 0; i < l; i++) {
		ar[s[i]-'A'] += 1;
		if (ar[0] == ar[1] && ar[1] == ar[2]) {
			count++;
			sum += count;
		}
	}
	
	
	cout << sum << endl;
	return 0;
}