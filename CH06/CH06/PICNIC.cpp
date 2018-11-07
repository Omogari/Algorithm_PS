#include<iostream>
using namespace std;

int student, soulmateCount;
bool soulmate[10][10];

int countPairing(bool matching[10]) {



}

int main(void) {

	int num, f1, f2;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> student >> soulmateCount;
		
		memset(soulmate, false, sizeof(soulmate));


		for (int j = 0; j < soulmateCount; j++) {
			cin >> f1 >> f2;
			soulmate[f1][f2] = soulmate[f2][f1] = true;

		}

	}


	return 0;
}