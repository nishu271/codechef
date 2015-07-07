#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

const int max_char = 256, max_size = 1000000+5;
char dict[max_char];
int _find[max_char];
char S[max_size];
void decode() {
	for (int i = 0; i < strlen(S); i++) {
		if (_find[S[i]]) S[i] = dict[S[i]];
	}
}
void remove_trail() {
	int dot_id = -1;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == '.') {
			dot_id = i;
			break;
		}
	}
	if (dot_id == -1) return;
	int i = strlen(S) - 1;
	for (; i > dot_id && S[i] == '0'; i--);
	if (i == dot_id) S[i] = '\0';
	else S[i+1] = '\0';

	if (i == dot_id && dot_id == 0){
		S[0] = '0';
		S[1] = '\0';
//		cout << "voila" << endl;
	}
}
int remove_lead() {
	int i = 0;
	for (; i < strlen(S) && S[i] == '0'; i++);
	//cout << i << " " << strlen(S) << endl;
	if (i == strlen(S)) return i-1;
	else return i;
}
int main () {
	int T, N;
        char ci, pi, x;
	cin >> T;
	while (T--) {
		memset(_find, 0, sizeof(_find));
		scanf("%d", &N);
		while (N--) {
			while (scanf("%c", &x) && (x == ' ' || x == '\n'));
			ci = x;
			while (scanf("%c", &x) && (x == ' ' || x == '\n'));
			pi = x;
			dict[ci] = pi;
			_find[ci] = 1;
			//cout << ci << " " << pi << endl;
		}
		scanf("%s", S);
		decode();
		remove_trail();
		int id = remove_lead();
		printf("%s\n", S+id);

	}
}
