#include <iostream>
#include <cstring>

using namespace std;


int area(int *r) {
	return (r[2] - r[0]) * (r[3] - r[1]);
}
int _max(int a, int b) {
	return a > b? a : b;
}
int _min(int a, int b) {
	return a < b? a: b;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		int x[4],y[4],e[4],a=0,b=0,m=1001,n=1001;
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		cin >> y[0] >> y[1] >> y[2] >> y[3];
		e[0] = _max(x[0], y[0]);
		e[1] = _max(x[1], y[1]);
		e[2] = _min(x[2], y[2]);
		e[3] = _min(x[3], y[3]);
		if ((x[2] <= y[0]  || x[3] <= y[1]) ||(x[0] >= y[2] ||x[1] >= y[3]))cout << area(x) + area(y) << endl;
		else cout << area(x) + area(y) - area(e) << endl;
	}
}