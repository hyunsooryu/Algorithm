#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//선행된것들 중 가장 큰 시간이 내가 시작될 시간
//정답은 가장 큰 시간 
int ind[10001];
int time[10001];
int D[10001];
vector<int> A[10001];
int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t; cin >> t;
		time[i] = t;
		while (true) {
			int x; cin >> x;
			if (x == -1) {
				break;
			}
			A[x].push_back(i);
			ind[i] += 1;
		}
	}
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) {
			D[i] = time[i];
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();

		for (auto j : A[tmp]) {
			ind[j] -= 1;
			if (D[j] < D[tmp]) {
				D[j] = D[tmp];
			}
			if (ind[j] == 0) {
				D[j] += time[j];
				Q.push(j);
			}
		}
	}
	//for문 귀찮을때.
	for_each(D + 1, D + N + 1,[](int N) {cout << N << " ";});







	return 0;
}