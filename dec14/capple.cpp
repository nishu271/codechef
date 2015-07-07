//#include <set>
#include <iostream>
#include <bitset>
#include <cstdio>
#include <cstring>
using namespace std;

const int n_max = 100005;
int main () {
    int T, N, n, ans;
    scanf("%d", &T);
//  set<int> s;
//  bitset<n_max> s; 
    int s[n_max];
    while (T--) {
	scanf("%d", &N);
//	s.clear();
//      s.reset();
	memset(s, 0, sizeof(s));
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		s[n] = 1;
	}
	ans = 0;
	for (int i = 1; i < n_max; i++) {
		ans += s[i];
	}
	cout << ans << endl;
	//cout << s.count() << endl;
    }
}
