#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//Topological _ sort with condition using priority_queue
int N, M;
vector<int> A[32001];
int ind[32001];
int main() {
	cin >> N >> M;
	while (M--) {
		int x, y;
		cin >> x >> y;
		A[x].push_back(y);
		ind[y] += 1;
	}

	priority_queue<int, vector<int>, greater<int>> Q;

	for (int i = 1; i <= N; i++){
		if (ind[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		auto tmp = Q.top();
		Q.pop();
		cout << tmp << " ";
		for (const auto j : A[tmp]) {
			ind[j] -= 1;
			if (ind[j] == 0) {
				Q.push(j);
			}
		}
	}











	return 0;
}