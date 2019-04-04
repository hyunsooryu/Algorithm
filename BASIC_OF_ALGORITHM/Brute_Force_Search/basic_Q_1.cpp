#include <iostream>
#include <algorithm>
#include <numeric>
int A[9];
using namespace std;
//9명중 7명을 찾아도 되지만,
//9명의 합 - 2명의 합이 100이되는, 2명을 찾아도된다.
//9명 중 2명을 고르는 경우의 수 9 * 8 / 2 * 1
//순서가 상관없기 때문에 36가지의 경우가 된다.

//이중 for문
void usingFor() {
	sort(A, A + 9);
	int total = accumulate(A, A + 9, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) {
				continue;
			}
			if (total - A[i] - A[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << A[k] << " ";
				}
				return;
			}
		}
	}
}
int path[9];
int cnt = 0;

bool go(int index, int start, int N, int M, int total) {
	if (index == M) {
		cnt += 1;
		cout << path[0] << " 와 " << path[1] << " 에 대하여 검사중입니다.";
		cout << endl;
		if (total - A[path[0]] - A[path[1]] == 100) {
			for (int k = 0; k < 9; k++) {
				if (k == path[0] || k == path[1]) {
					continue;
				}
				cout << A[k] << " ";
			}
			return true;
		}
		return false;
	}

	for (int i = start; i < N; i++) {
		path[index] = i;
		auto tmp = go(index + 1, i + 1, N, M, total);
		if (tmp) {
			return true;
		}
	}
	return false;
}
//재귀적 탐색
void usingRecursive() {
	sort(A, A + 9);
	int total = accumulate(A, A + 9, 0);
	go(0, 0, 9, 2, total);

	cout << cnt << endl;
}



//순열
void usingNextPermutation() {
	//next_permutation을 사용한다.
}
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
	}
	usingRecursive();
	












	return 0;
}