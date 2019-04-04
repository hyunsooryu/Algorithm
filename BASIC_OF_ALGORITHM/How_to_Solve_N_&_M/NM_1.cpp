//중복 불가 수열
#include <iostream>
using namespace std;
bool V[10];
int A[10];
int N, M;

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (V[i]) continue;
		V[i] = true; A[index] = i;
		go(index + 1, n, m);
		V[i] = false;
	} 
}

int main() {
	cin >> N >> M;
	go(0, N, M);













	return 0;
}