#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int cache[100][100];
string W, S;

bool match(int w, int s) {

	while (w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?')) {
		w++;
		s++;
	}

	//memoization
	int &ret = cache[w][s];
	if (ret != -1) return ret;

	if (w == W.size()) {
		return ret = (W.size() == S.size());
	}

	if (W[w] == '*') {
		//? if(match(w+1,s))
	}

}

int main(void) {

	int num, n;
	cin >> num;
	for (int a = 0; a < num; a++) {
		cin >> W;	//wildcard pattern

		cin >> n;	//num of filenames
		for (int b = 0; b < n; b++) {
			cin >> S;	//filename

			memset(cache, -1, sizeof(cache));


		}
	}
	return 0;
}