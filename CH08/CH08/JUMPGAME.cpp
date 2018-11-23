#include<iostream>
using namespace std;

int checkJump[100][100];
int gameBoard[100][100];

int jump(int a, int b) {
	int now = gameBoard[a][b];

	//base case : if we jump out of the game board 
	if (now == -1) return 0;

	//base case : if we arrive at 0
	if (now == 0) return 1;

	int &ret = checkJump[a][b];
	if (ret != -1) return ret;
	
	jump(a + now, b);

}

int main(void) {

	int num;
	cin >> num;

	for (int a = 0; a < num; a++) {

		int N;
		cin >> N;
		//initialize checkJump, gameBoard
		memset(checkJump, -1, sizeof(checkJump));
		memset(gameBoard, -1, sizeof(gameBoard));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> gameBoard[i][j];
			}
		}



	}
	return 0;
}