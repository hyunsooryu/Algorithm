#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A[1001][1001];
int V[1001][1001];

int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
int cnt_tomato = 0;
int MAX_DAY = 0;

bool possible(int i, int j) {
	if (i >= 0 && j >= 0 && i < M && j < N) {
		return V[i][j] == 0 && A[i][j] != -1;
	}
	return false;
}

int main() {
	cin >> N >> M;
	queue<pair<int, int>> Q;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 0) {
				cnt_tomato += 1;
			}
			else if (A[i][j] == 1) {
				cnt_tomato += 1;
				V[i][j] = 1;
				Q.push(make_pair(i, j));
			}
		}
	}

	if (cnt_tomato == 0) {
		cout << 0 << endl;
	}
	else {
		while (!Q.empty()) {
			auto tmp = Q.front();
			Q.pop();
			cnt_tomato -= 1;
			if (V[tmp.first][tmp.second] > MAX_DAY) {
				MAX_DAY = V[tmp.first][tmp.second];
			}
			int i = tmp.first;
			int j = tmp.second;
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (possible(ni, nj)) {
					V[ni][nj] = V[i][j] + 1;
					Q.push(make_pair(ni, nj));
				}
			}
		}

		if(cnt_tomato == 0) {
			cout << MAX_DAY - 1 << endl;
		}
		else {
			cout << -1 << endl;
		}

	}
	

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << V[i][j] << " ";
		}
		cout << endl;
	}
	

	



	















	return 0;
}