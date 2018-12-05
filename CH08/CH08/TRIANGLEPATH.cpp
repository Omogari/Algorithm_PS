#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int triangle[100][100];
int cache[100][100];
int n;	//size of triangle

int findMaxSumPath(int y, int x) {
	//memoization
	int &ret = cache[y][x];
	if (ret != 0) return ret;

	//base case
	if (y == n - 1) return ret = triangle[y][x];

	return ret = triangle[y][x] + max(findMaxSumPath(y + 1, x), findMaxSumPath(y + 1, x + 1));
}

int main(void) {

	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> triangle[i][j];
			}
		}
		//initialize cache
		memset(cache, 0, sizeof(cache));

		cout << findMaxSumPath(0, 0) << endl;
	}
	return 0;
}