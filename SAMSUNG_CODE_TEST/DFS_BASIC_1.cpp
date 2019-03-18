#include <iostream>
#include <algorithm>

using namespace std;

//DFS 
int A[9];
int S;
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
		S += A[i];
	}
	sort(A, A + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) {
				continue;
			}
			if (S - A[i] - A[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != j && k != i) {
						cout << A[k] << " ";
					}
				}
				cout << endl;
				break;
			}
		}
	}

	return 0;
}