#include "pch.h"
#include <queue>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
int N, M;
int D[101][101];
int A[101][101];
bool V[101][101];

bool possiblePos(int i, int j) {
	return (i >= 1 && j >= 1 && i <= N && j <= M) && (!V[i][j]);
}

struct pair_cmp{
	bool operator()(const pair<pair<int,int>,int>& X, const pair<pair<int,int>,int>& Y)const{
		return X.second > Y.second;
	}
};

int BFSwithHeap(int N, int M) {
	priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, pair_cmp> Q;
	Q.push(make_pair(make_pair(1,1),A[1][1]));
	V[1][1] = true;
	D[1][1] = 0;

	while (!Q.empty()) {
		auto i = Q.top().first.first;
		auto j = Q.top().first.second;
		Q.pop();
		if (i == N && j == M) {
			return D[i][j];
		}
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (possiblePos(ni, nj)) {
				V[ni][nj] = true;
				if (A[ni][nj] == 1) {
					D[ni][nj] = D[i][j] + 1;
				}
				else {
					D[ni][nj] = D[i][j];
				}
				Q.push(make_pair(make_pair(ni, nj), A[ni][nj]));
			}
		}

	}
	return -1;
}



int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}

	cout << BFSwithHeap(N, M) << endl;

	return 0;
}
