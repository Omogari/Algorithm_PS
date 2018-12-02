#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int cache[101][101];
string W, S;

int match(int w, int s) {

	//memoization
	int &ret = cache[w][s];
	if (ret != -1) return ret;

	while (w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?')) {
		w++;
		s++;
	}

	if (w == W.size()) {
		return ret = (s == S.size());
	}

	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (match(w + 1, s + skip)) {
				return ret = 1;
			}
		}
	}
	return ret = 0;
}

int main(void) {

	int num, n;
	cin >> num;
	for (int a = 0; a < num; a++) {
		vector<string> v;
		cin >> W;	//wildcard pattern

		cin >> n;	//num of filenames
		for (int b = 0; b < n; b++) {
			cin >> S;	//filename
				
			memset(cache, -1, sizeof(cache));
			if (match(0, 0) == 1)
				v.push_back(S);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}