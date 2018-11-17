#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int fenceArea(vector<int> &fence) {

	//base case
	if (fence.size() == 1) return fence[0];

	int mid = fence.size() / 2;
	vector<int> fenceLeft;
	vector<int> fenceRight;

	if (fence.size() % 2 == 0) {
		fenceLeft.resize(mid);
		fenceRight.resize(mid);
	}
	else {
		fenceLeft.resize(mid);
		fenceRight.resize(mid + 1);
	}
	copy(fence.begin(), fence.begin() + mid, fenceLeft.begin());
	copy(fence.begin() + mid, fence.end(), fenceRight.begin());
	

	int ret = max(fenceArea(fenceLeft), fenceArea(fenceRight));

	//the case when maximal rectangular cover both left side and right side 
	int coverRec = 2 * min(fence[mid - 1], fence[mid]);
	ret = max(ret, coverRec);
	int left = mid - 1;
	int right = mid;

	while (left >= 0 && right <= fence.size() - 1) {
		if (right < fence.size() - 1) {
			if (left == 0 || fence[left - 1] <= fence[right + 1]) {
				right++;
				coverRec = (right - left + 1) * min(coverRec / (right - left), fence[right]);
			}
			else if (fence[left - 1] > fence[right + 1]) {
				left--;
				coverRec = (right - left + 1) * min(coverRec / (right - left), fence[left]);
			}
		}
		else if (left > 0) {
			left--;
			coverRec = (right - left + 1) * min(coverRec / (right - left), fence[left]);
		}
		ret = max(ret, coverRec);
		if (left == 0 && right == fence.size() - 1) break;
	}
	return ret;
}

int main(void) {

	int num;
	cin >> num;
	
	for (int a = 0; a < num; a++) {

		int N;
		cin >> N;
		vector<int> fence(N);
		for (int i = 0; i < N; i++) {
			cin >> fence[i];
		}

		cout << fenceArea(fence) << endl;

	}

	return 0;
}