//비내림차순에서의 수열 (중복가능)
#include <iostream>
using namespace std;

int A[10];

void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; i++) {
		A[index] = i;
		go(index + 1, i, n, m);
	}

}


int main() {
	int N, M;
	cin >> N >> M;

	go(0, 1, N, M);










	return 0;
}