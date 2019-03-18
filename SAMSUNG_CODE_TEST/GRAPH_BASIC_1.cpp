#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A[2001];
bool V[2001];

bool DFS(int from, int cnt) {
	cout << from << " " << cnt << endl;
	if (cnt == 5) {
		return true;
	}
	auto tmp = false;
	for (auto j : A[from]) {
		if (!V[j]) {
			V[j] = true;
			tmp = DFS(j, cnt + 1);
			if (tmp) {
				return tmp;
			}
			V[j] = false;
		}
	}
	return tmp;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from; int to;
		cin >> from >> to;
		A[from].push_back(to);
		A[to].push_back(from);
	}

	for (int i = 0; i < N; i++) {
		V[i] = true;
		auto result = DFS(i, 1);
		V[i] = false;
		if (result) {
			cout << 1 << endl;
			return 0;
		}
	}

	cout << 0 << endl;











	return 0;
}