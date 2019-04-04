#include <iostream>
using namespace std;
int A[10];
void go(int i, int size, int n, int m) {
	if (size == m) {
		for (int k = 0; k < m; k++) {
			cout << A[k] << " ";
		}
		cout << endl;
		return;
	}
	if (i > n) {
		return;
	}

	//날 먹는다.
	A[size] = i;
	go(i + 1, size + 1, n, m);
	//날 먹지 않는다.
	go(i + 1, size, n, m);
	
}

int main() {
	int N, M;
	cin >> N >> M;
	go(1, 0, N, M);










	return 0;
}