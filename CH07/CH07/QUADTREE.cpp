#include<iostream>
#include<vector>
#include<string>
using namespace std;

string quadTreeReverse(string::iterator &it) {
	char head = *it;
	it++;

	//base case
	if (head == 'w' || head == 'b') return string(1, head);

	string upLeft = quadTreeReverse(it);
	string upRight = quadTreeReverse(it);
	string downLeft = quadTreeReverse(it);
	string downRight = quadTreeReverse(it);
	return string("x") + downLeft + downRight + upLeft + upRight;
}

int main(void) {

	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {

		string input;
		cin >> input;
		
		string::iterator it = input.begin();
		cout << quadTreeReverse(it) << endl;

	}
	return 0;
}