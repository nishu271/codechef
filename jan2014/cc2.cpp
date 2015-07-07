#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int _max(int x, int y) { return x > y?x:y;}
int _min(int x, int y) { return x < y?x:y;}
int ar[101];

int gcd(int x, int y) {
	int t1, t2;	
	t1 = _min(x,y);
	t2 = _max(x,y);
	x = t1;
	y = t2;
	//cout << x << " " << y << endl;
	
	if (y % x == 0) return x;
	
	int a = x;
	x = y % x;
	//cout << x << " " << y << endl;
	y = a;
	//cout << x << " " << y << endl;
	return gcd(x,y); 
}
int grundy(int x, int y) {
	int t1,t2;
	t1 = _min(x,y);
	t2 = _max(x,y);
	x = t1;
	y = t2;
	if (x == 1) return 1;
	int a = grundy(y % x, x);
	//cout << "grundy " << y % x << "," << x << " = " << a<< endl;
	if (a > y/x) {
		if (y/x == 1) return 0;
		else return y/x - 1;
	}
	else if (a == y/x) return a-1;
	
	else return y/x; 
}
int main () {
	bool win=false;
	int t;
	scanf ("%d", &t);
	while(t--) {
		int n,c,t;
		scanf("%d", &n);
		memset(ar, 0, sizeof(ar));
		int i = 0;
		for (int i = 0; i < n; i++) {
			int x,y;
			scanf("%d%d", &x, &y);
			
			int t1,t2;
			t1 = _min(x,y);
			t2 = _max(x,y);
			x = t1;
			y = t2;
			int a = gcd(x,y);
			x = x / a;
			y = y / a;
			ar[i] = grundy(x,y);
			//cout << "x = " << x << ", y = " << y << ", gcd (x,y) = " << a << ", ar[i] = " << ar[i] << endl;
		}
		int res = ar[0];
		for (int i = 1; i < n; i++) {
			res = res ^ ar[i]; 
			//cout << "ar[i] = " << ar[i] << " " << res << endl;
		}
		if (res) printf("YES\n");
		else printf("NO\n");
	}
}