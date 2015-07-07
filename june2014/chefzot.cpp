#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
	int N, A;
	int prev = 0;
	int ans = 0;
	cin >> N;
	for (int i=1; i <= N; i++) {
		cin >> A;
		if (!A) {
			ans = ans > i - prev - 1? ans: i-prev-1;
			prev = i;
		}
	}
	ans = ans > N - prev? ans : N - prev;
	cout << ans << endl;
}
