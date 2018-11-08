#include<iostream>
using namespace std;

int h, w;
bool board[20][20];
char piece;	//'#' OR '.'
bool * head;

int countCovering(bool * head) {
	int ret = 0;

	//if *head arrive at last piece, and the piece is true, then it is successful case.
	if (*head == board[h - 1][w - 1] && board[h - 1][w - 1] == true) return 1;

	if (*head == true) {
		head++;
	}
	else {

	}



}

int main(void) {

	int num, countWhitePiece = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {

		//Initialize Board
		cin >> h >> w;
		memset(board, false, sizeof(board));
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> piece;
				if (piece == '#') {
					board[j][k] = true;
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