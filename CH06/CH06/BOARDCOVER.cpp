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

bool set(vector<vector<int>> &board, int y, int x, int type, int delta) {
	
	bool ret = false;
	int ny, nx;

	for (int i = 0; i < 3; i++) {
		ny = y + coverType[type][i][1];
		nx = x + coverType[type][i][0];

		if (ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size()) {
			ret = false;
			break;
		}
		else {
			ret = true;
		}


	}

	return ret;
}

int cover(vector<vector<int>> &board) {
	int ret = 0;

	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	return ret;
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