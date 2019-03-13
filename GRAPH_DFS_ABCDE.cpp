#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//A, B, C, D, E Question //JUST FOR FIND THE DEEP SIDE //GIVE ALL VERTEX AN OPPORTUNITY TO MAKE DFS DEEP IN SIDE

int P[2001];
int D[2001];
vector<int> A[2001];

void path_finder(int N) {
	if (P[N] == -1) {
		cout << N << " ";
		return;
	}
	path_finder(P[N]);
	cout << N << " ";
}

bool DFS(int N) {
	if (D[N] == 5) {
		return true;
	}
	for (auto j : A[N]) {
		if (D[j] == 0) {
			D[j] = D[N] + 1;
			auto tmp = DFS(j);
			if (tmp == true) {
				return true;
			}
		}
	}
	return false;
}
int N, M;
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	auto flag = false;
	for (int i = 0; i < N; i++) {
		memset(D, 0, sizeof(D));
			D[i] = 1;
			flag = DFS(i);
			if (flag) {
				cout << 1 << endl;
				break;
			}
	}
	if (!flag) {
		cout << 0 << endl;
	}
















	return 0;
}
