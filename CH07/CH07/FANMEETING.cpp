#include<iostream>
#include<vector>
#include<string>
using namespace std;



int hugs(string &members, string &fans) {

	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; i++) B[M-i-1] = (fans[i] == 'M');

	

}

int main(void) {

	int num;
	cin >> num;
	for (int a = 0; a < num; a++) {

		string members;
		string fans;
		cin >> members >> fans;






	}
	return 0;
}