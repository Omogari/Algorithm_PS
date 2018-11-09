#include<iostream>
#include<vector>
using namespace std;

int h, w;
char piece;	//'#' OR '.'
int coverType[4][3][2] = {
	{ { 0,0 },{ 1,0 },{ 0,1 } },
	{ { 0,0 },{ 1,1 },{ 0,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } },
};

int countCovering(vector<vector<int>> &board, int y, int x, int delta) {
	int ret = 0;

	//Base case
	if () return 1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			int ny = y + coverType[i][j][1];
			int nx = x + coverType[i][j][0];

		}
	}



}

int main(void) {

	int num, countWhitePiece = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {

		//Initialize Board
		cin >> h >> w;
		vector<vector<int>> board(h, vector<int>(w, 0));
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> piece;
				if (piece == '#') {
					board[j][k] = 1;
				}
				else {
					countWhitePiece++;
				}
			}
		}

		//if number of pieces is not divided by 3, count = 0.
		if (countWhitePiece % 3 != 0) {
			cout << 0 << endl;
			exit(-1);
		}



	}

	return 0;
}