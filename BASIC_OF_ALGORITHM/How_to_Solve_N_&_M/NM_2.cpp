//중복 불가 오름차순의 수열
#include <iostream>
using namespace std;
//NM2
int A[10];
bool V[10];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; i++) {
		//if (V[i]) continue;
		//V[i] = true;
		A[index] = i;
		go(index + 1, i + 1, n, m);
		//V[i] = false;
	}
	
}

int main() {
	int N, M;
	cin >> N >> M;
	go(0, 1, N, M);






	return 0;
}