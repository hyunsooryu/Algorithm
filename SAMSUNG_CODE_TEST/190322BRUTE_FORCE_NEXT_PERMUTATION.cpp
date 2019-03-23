#include <iostream>
#include <vector>
using namespace std;

bool Next_Permutation(int* A, int size) {
	int i = size - 1;
	int j = size - 1;
	auto flag = false;
	for (; i > 0; i--) {
		if (A[i - 1] < A[i]) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		return false;
	}
	for (; j >= i; j--) {
		if (A[i - 1] < A[j]) {
			swap(A[i - 1], A[j]);
			break;
		}
	}
	int S = i;
	int E = size - 1;
	while (S < E) {
		swap(A[S], A[E]);
		S += 1;
		E -= 1;
	}
	return true;
}
int A[10001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (Next_Permutation(A, N)) {
		for (int i = 0; i < N; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}












	return 0;
}