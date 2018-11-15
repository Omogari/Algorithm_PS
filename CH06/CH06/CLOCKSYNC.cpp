#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 987654321;
const int clockSwitch[10][16] = {
	{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1 },
	{ 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1 },
	{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0 }
};

void push(vector<int> &clocks, int sw) {
	for (int i = 0; i < 16; i++) {
		clocks[i] += clockSwitch[sw][i];
		if (clocks[i] == 4) {
			clocks[i] = 0;
		}
	}
}

bool checkTwelve(vector<int> &clocks) {
	bool ret = true;
	for (int i = 0; i < 16; i++) {
		if (clocks[i] != 3) {
			ret = false;
			break;
		}
	}
	return ret;
}

int solve(vector<int> &clocks, int sw) {
	//if all switches were pushed, check where clocks point out.
	if (sw == 10) return checkTwelve(clocks) ? 0 : INF;

	int ret = INF;
	for (int count = 0; count < 4; count++) {
		ret = min(ret, count + solve(clocks, sw + 1));
		//cout << ret;
		push(clocks, sw);
	}
	return ret;
}

int main(void) {

	int num;
	cin >> num;

	for (int a = 0; a < num; a++) {

		vector<int> clocks(16);
		//3->0, 6->1, 9->2, 12->3
		for (int i = 0; i < 16; i++) {
			cin >> clocks[i];
			clocks[i] = clocks[i] / 3 - 1;
		}

		int ret = solve(clocks, 0);
		if (ret >= INF) {
			cout << -1 << endl;
		}
		else {
			cout << ret << endl;
		}

	}

	return 0;
}
