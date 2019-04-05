#include <iostream>
#include <algorithm>
using namespace std;
int N;
int W[10][10];
int A[10];
int MIN = 100000000;
//외판원순회2문제
//(N - 1)! * N if using next_permutation N <= 10
//다이나믹 프로그래밍으로도 해결해낼 수 있습니다. BIT_MASK
//N제한이 10보다 작기 때문에, 사용이가능합니다.
 void cal() {
	 int total = 0;
	 if (W[A[N - 1]][A[0]] == 0) {
		 return;
	 }
	 for (int i = 1; i < N; i++) {
		 if (W[A[i - 1]][A[i]] == 0) {
			 return;
		 }
		 total += W[A[i - 1]][A[i]];
	}
	total += W[A[N - 1]][A[0]];
	if (total < MIN) {
		MIN = total;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		A[i] = i;
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	do {
		cal();
	} while (next_permutation(A + 1, A + N)); //왜 A + 1부터 next_permutation을 하였는지 잘 remind

	cout << MIN << endl;
	









	return 0;
}