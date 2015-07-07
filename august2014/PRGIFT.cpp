#include <iostream>

using namespace std;

int main () {
	int T, N, k, c, a;
	cin >> T;
	while (T--) {
		cin >> N >> k;
		c = 0;
		int tmp = N;
		while (N--) {
			cin >> a;
			if (!(a&1)) c++;
		}
		if (k == 0 && c == tmp) cout << "NO" << endl;
		else if (c >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
