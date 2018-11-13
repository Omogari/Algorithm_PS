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

vector<int> push(vector<int> &clockes, const int sw[16]) {
	for (int i = 0; i < 16; i++) {
		clockes[i] += sw[i];
		if (clockes[i] == 4) {
			clockes[i] = 0;
		}
	}
	return clockes;
}

bool checkTwelve(vector<int> &clockes) {
	bool ret = true;
	for (int i = 0; i < 16; i++) {
		if (clockes[i] != 3) {
			ret = false;
			break;
		}
	}
	return ret;
}

int solve(vector<int> &clockes, const int clockSwitch[10][16], int sw) {
	int ret = 0;
	if (sw == 10) return ret;

	//base case
	if (checkTwelve(clockes)) return 1;

	for (int count = 0; count < 4; count++) {
		ret = min(ret, count + solve(clockes, clockSwitch, sw+1));
		push(clockes, clockSwitch[sw]);
	}
	return ret;
}

int main(void) {

	int num;
	cin >> num;

	for (int a = 0; a < num; a++) {

		vector<int> clockes(16);
		//3->0, 6->1, 9->2, 12->3
		for (int i = 0; i < 16; i++) {
			cin >> clockes[i];
			clockes[i] = clockes[i] / 3 - 1;
		}

		int ret = solve(clockes, clockSwitch, 0);
		if (ret >= INF) {
			cout << -1 << endl;
		}
		else {
			cout << ret << endl;
		}

	}

	return 0;
}