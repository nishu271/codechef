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

const int buf_size = 1000000 + 5;
char buf[buf_size];
int main (int argc, char const *argv[])
{
	/* code */
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", buf);
		int i = 0, j = 0;
		int max_len = 0;
		int k = 0, l = strlen(buf);
		while (i >= 0 && k < l) {
			if(buf[k++]=='<') i++;
			else i--;
			j++;
			if (i == 0) {
				max_len += j;
				j = 0;
			}
		}
		printf("%d\n", max_len);
	}
	return 0;
}