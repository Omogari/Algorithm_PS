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

vector<int> push(vector<int> &clocks, const int sw[16]) {
	for (int i = 0; i < 16; i++) {
		clocks[i] += sw[i];
		if (clocks[i] == 4) {
			clocks[i] = 0;
		}
	}
	return clocks;
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

int solve(vector<int> &clocks, const int clockSwitch[10][16], int sw) {
	int ret = 0;
	if (sw == 10) return ret;

	//base case
	if (checkTwelve(clocks)) return 1;

	for (int count = 0; count < 4; count++) {
		ret = min(ret, count + solve(clocks, clockSwitch, sw+1));
		push(clocks, clockSwitch[sw]);
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

		int ret = solve(clocks, clockSwitch, 0);
		if (ret >= INF) {
			cout << -1 << endl;
		}
		else {
			cout << ret << endl;
		}

	}

	return 0;
}