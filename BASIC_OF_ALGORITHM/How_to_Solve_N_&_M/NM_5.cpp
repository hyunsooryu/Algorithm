#include <iostream>
#include <algorithm>
using namespace std;
int path[10];
int A[10];
bool V[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (V[i]) continue;
		path[index] = A[i];
		V[i] = true;
		go(index + 1, n, m);
		V[i] = false;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	go(0, N, M);





	return 0;
}