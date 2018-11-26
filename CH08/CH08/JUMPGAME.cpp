#include<iostream>
#include<cstring>
using namespace std;

int checkJump[100][100];
int gameBoard[100][100];
int N;

int jump(int a, int b) {
	int now = gameBoard[a][b];

	//base case : if we jump out of the game board 
	if (a >= N || b >= N) return 0;

	//base case : if we arrive at 0
	if (now == 0) return 1;

	int &ret = checkJump[a][b];
	if (ret != -1) return ret;
	
	ret = jump(a + now, b) || jump(a, b + now);
	return ret;
}

int main(void) {

	int num;
	cin >> num;

	for (int a = 0; a < num; a++) {

		cin >> N;
		//initialize checkJump, gameBoard
		memset(checkJump, -1, sizeof(checkJump));
		memset(gameBoard, -1, sizeof(gameBoard));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> gameBoard[i][j];
			}
		}

		if (jump(0, 0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	return 0;
}