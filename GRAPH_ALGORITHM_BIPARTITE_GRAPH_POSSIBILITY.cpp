#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int V[20001];
//BIPARTITE GRAPH OR NOT PROBLEM SOLVING
vector<int> A[20001];
int T;

bool DFS(int i, int color) {
	V[i] = color;
	auto flag = true;
	for (auto j : A[i]) {
		if (V[j] == 0) {
			flag = DFS(j, 3 - color);
			if (flag == false) {
				break;
			}
		}
		else if (V[j] == color) {
			flag = false;
			break;
		}
	}
	return flag;
}


int main() {
	cin >> T;
	while (T--) {
		memset(V, 0, sizeof(V));
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			A[x].push_back(y);
			A[y].push_back(x);
		}
		if (DFS(1, 1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		for (int i = 1; i <= N; i++) {
			cout << V[i] << " ";
		}
		cout << endl;
	}










	return 0;
}