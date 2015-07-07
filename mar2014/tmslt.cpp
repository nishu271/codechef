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
#include <sys/time.h>
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

const int n_max = 3000000+2;
const int s_max = 1000000;

int main (int argc, char const *argv[])
{
	long long int a, b, c, d, T, N;
	double secs, usecs;
	struct timeval tv;
	gettimeofday(&tv, 0);
	secs = tv.tv_sec;
	usecs = tv.tv_usec;
	//int hash[s_max];
	scanf("%lld", &T);
	map<int, int> hash;
	map<int, int> :: iterator it;
	while (T--) {
		scanf("%lld %lld %lld %lld %lld", &N, &a, &b, &c, &d);
		//memset(hash, 0, sizeof(hash));
		hash.clear();
		hash[d] = 1;
		int t1 = d, t2;
		for (int i = 1; i < N; i++) {
			t2 = ((((a * t1) % s_max) * t1) % s_max + (b * t1) % s_max + c) % s_max;
			if (hash.count(t2)) {
				hash[t2]++;
			} 
			else hash[t2] = 1;
			t1 = t2;
		}
		
		long long sum1 = 0;
		long long sum2 = 0;
		bool turn = 1;
		for (it = hash.begin(); it != hash.end(); it++) {
			a = it -> first;
			b = it -> second;
			if (b & 1) {
				if (turn) {
					sum1 += (b/2 + 1) * a;
					sum2 += (b/2) * a;
				}
				else {
					sum1 += (b/2) * a;
					sum2 += (b/2 + 1) * a;
				}
				turn = !turn;
			}
			else {
				sum1 += (b/2) * a;
				sum2 += (b/2) * a;
			}
		}
		//cout << sum1 << " " << sum2 << endl;
		//cout << "here 2" << endl;
		printf("%lld\n",abs(sum1 - sum2));
	}
	gettimeofday(&tv, 0);
	cout << "Time Taken : " << tv.tv_sec - secs + (tv.tv_usec - usecs) / 1000000 << " secs"<< endl;
	return 0;
}