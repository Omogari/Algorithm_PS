#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<char> section;
vector<vector<char>> quadTree(4, vector<char>());

int main(void) {

	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {

		vector<string> v;
		string input;
		while (getline(cin, input)) {
			v.push_back(input);
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}

	}
	return 0;
}