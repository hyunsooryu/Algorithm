//중복가능 수열
#include <iostream>
using namespace std;

int A[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		A[index] = i;
		go(index + 1, n, m);
	}

}


int main() {
	int N, M;
	cin >> N >> M;

	go(0, N, M);










	return 0;
}