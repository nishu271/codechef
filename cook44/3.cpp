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

const int s_max = 1000005;
char s[1000005];
int ar[s_max][3];
int main (int argc, char const *argv[])
{
	/* code */
	scanf("%s", s);
	int l = strlen(s);
	memset(ar, 0, sizeof(ar));
	for (int i = 0; i < l; i++) {
		if (i == 0) {
			ar[i][s[i]-'A'] = 1;
		}
		else {
			ar[i][s[i]-'A'] = 1 + ar[i-1][s[i]-'A'];
			ar[i][(s[i]-'A' + 1) % 3] = ar[i-1][(s[i]-'A' + 1) % 3];
			ar[i][(s[i]-'A' + 2) % 3] = ar[i-1][(s[i]-'A' + 2) % 3];
		}
	}
	long long sum= 0;
	int count = 0;
	for (int i = 1; i < l; i++) {
		if (ar[i][0] == ar[i][1] && ar[i][1] == ar[i][2]) {
			count++;
			sum += count;
		}
	}
	for (int i = 1; i < l; i++) {
		count = 0;
		for (int j = i+1; j < l; j++) {
			if(ar[j][0] - ar[i-1][0] == ar[j][1] - ar[i-1][1] && ar[j][2] - ar[i-1][2] == ar[j][1] - ar[i-1][1]) {
				count++;
				sum += count;
			}
		}
	}
	cout << sum << endl;
	return 0;
}