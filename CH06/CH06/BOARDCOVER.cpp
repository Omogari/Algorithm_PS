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
	
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
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

	//base case
	if (y == -1) return 1;

	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}
		set(board, y, x, type, -1);
	}

	return ret;
}

int main(void) {

	int num, countWhitePiece;
	cin >> num;

	for (int i = 0; i < num; i++) {
		countWhitePiece = 0;

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
		}
		else {
			cout << cover(board) << endl;
		}
	}
	return 0;
}