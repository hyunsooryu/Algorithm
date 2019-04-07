#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//DAG Topological_sort with queue -> HOW TO SORT FLOW OF WORKS

//Starting_point = indegree = 0
int ind[32001];
vector<int> A[32001];
queue<int> Q;
int N, M;
int main() {
	cin >> N >> M;
	while (M--) {
		int pre, post;
		cin >> pre >> post;
		A[pre].push_back(post);
		ind[post] += 1;
	}
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		cout << tmp << " ";
		for (auto j : A[tmp]) {
			ind[j] -= 1;
			if (ind[j] == 0) {
				Q.push(j);
			}
		}
	}
	cout << endl;









	return 0;
}