#include <iostream>
#include <vector>
using namespace std;


void Q_SORT(int i, int j, vector<int> TMP, vector<int>& REAL) {
	if (i > j || i == j) {
		if (i > j) {
			return;
		}
		if (i == j) {
			REAL[i] = TMP[0];
			return;
		}
	}
	vector<int> LEFT;
	vector<int> RIGHT;
	int size = TMP.size();
	int pivot = TMP[0];
	for (int i = 1; i < size; i++) {
		if (TMP[i] > pivot) {
			RIGHT.push_back(TMP[i]);
		}
		else {
			LEFT.push_back(TMP[i]);
		}
	}
	int L_SIZE = LEFT.size();
	int R_SIZE = RIGHT.size();
	REAL[i + L_SIZE] = pivot;
	Q_SORT(i, i + L_SIZE - 1, LEFT, REAL);
	Q_SORT(i + L_SIZE + 1, i + L_SIZE + R_SIZE, RIGHT, REAL);
}
	

int main() {
	vector<int> A = {10,9,8,7,6,5,4,3,2,1};
	Q_SORT(0, A.size() - 1, A, A);
	for (auto j : A) {
		cout << j << " ";
	}
	cout << endl;






	return 0;
}