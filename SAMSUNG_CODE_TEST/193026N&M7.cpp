//같은 수를 여러번 골라도 된다. N개중 몇개를 뽑는 경우의 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int A[8];

void go(int index, int cnt, vector<int>& path) {
	if (cnt == K) {
		for (auto j : path) {
			cout << A[j] << " ";
		}
		cout << endl;
		return;
	}
	if (index > N) {
		return;
	}
	for (int i = 0; i < N; i++) {
		path.push_back(i);
		go(i, cnt + 1, path);
		path.pop_back();
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	vector<int> path;
	go(0, 0, path);












	return 0;
}