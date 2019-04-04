#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int cnt[10];
int A[10];
int path[10];
vector<int> T;

void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i < n; i++) {
		if (cnt[i] > 0) {
			cnt[i] -= 1;
			path[index] = T[i];
			go(index + 1, i, n, m);
			cnt[i] += 1;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	} //정렬 후 중복제거 후 정제된 데이터 셋
	sort(A, A + N); //정렬 후
	cnt[0] = 1;
	T.push_back(A[0]);
	int k = 0;
	for (int i = 1; i < N; i++) {
		if (A[i - 1] == A[i]) {
			cnt[k] += 1;
		}
		else {
			T.push_back(A[i]);
			cnt[++k] = 1;
		}
	}
	go(0, 0, T.size(), M);

	













	return 0;
}