#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
char A[51][51];
int V[51][51];

int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
int N, M;

bool Possible_W(int i, int j) {
	if (i >= N || j >= M || i < 0 || j < 0) {
		return false;
	}
	if ((A[i][j] == 'S' || A[i][j] == '.')) {
		return true;
	}
	return false;
}
bool Possible_S(int i, int j) {
	if (i >= N || j >= M || i < 0 || j < 0) {
		return false;
	}
	if (A[i][j] == '.' || A[i][j] == 'D') {
		if (A[i][j] == 'D') {
			return true;
		}
		else {
			for (int k = 0; k < 4; k++) {
				if ((A[i + di[k]][j + dj[k]] == '*')) {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

queue<pair<int, int>> Q;
vector<pair<int, int>> WATER;
int main() {
	auto flag = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '*') {
				V[i][j] = 1;
				WATER.push_back(make_pair(i, j));
			}
			else if (A[i][j] == 'S') {
				V[i][j] = 1;
				Q.push(make_pair(i, j));
			}
		}
	}

	for (auto j : WATER) {
		V[j.first][j.second] = 1;
		Q.push(pair<int,int>(j.first, j.second));
	}

	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();

		int i = tmp.first;
		int j = tmp.second;
		int ID = A[i][j];

		
		if (ID == 'S') {
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (Possible_S(ni, nj)){
					if (A[ni][nj] == 'D') {
						flag = true;
						cout << V[i][j] << endl;
					}
					V[ni][nj] = V[i][j] + 1;
					A[ni][nj] = 'S';
					Q.push(make_pair(ni, nj));
				}
			}
			if (flag) {
				break;
			}
		}
		else {
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (Possible_W(ni, nj)) {
					V[ni][nj] = V[i][j] + 1;
					A[ni][nj] = '*';
					Q.push(make_pair(ni, nj));
				}
			}
		}
		cout << "________________________" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		cout << "________________________" << endl;

	}

	if (!flag) {
		cout << "KATUS" << endl;
	}

	












	return 0;
}