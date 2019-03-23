#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string A[20];
vector<pair<int, int>> POS;
map<pair<int, int>, int> MAP;
int N, M;
int D[20][20];
bool V[20][20];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

int DIST[10][10][10][10];


bool isPossiblePos(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}
void BFS(pair<int,int> X) {
	memset(D, 0, sizeof(D));
	memset(V, false, sizeof(V));
	queue<pair<int, int>> Q;
	D[X.first][X.second] = 0;
	V[X.first][X.second] = true;
	Q.push(X);
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int i = tmp.first;
		int j = tmp.second;
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (isPossiblePos(ni,nj) && !V[ni][nj]) {
				if (A[ni][nj] == 'x') {
					continue;
				}
				else if (A[ni][nj] == '.') {
					D[ni][nj] = D[i][j] + 1;
					V[ni][nj] = true;
					Q.push(make_pair(ni, nj));
				}
				else {
					D[ni][nj] = D[i][j] + 1;
					V[ni][nj] = true;
					cout << D[ni][nj] << endl;
					DIST[X.first][X.second][ni][nj] = D[ni][nj];
					DIST[ni][nj][X.first][X.second] = D[ni][nj];
					Q.push(make_pair(ni, nj));
				}
			}
		}
	}
}

int main() {
	int s = 0;
	int e = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '*') {
				POS.push_back(make_pair(i, j));
			}
			else if (A[i][j] == 'o') {
				s = i;
				e = j;
			}
		}
	}
	
	vector<int> TMP(POS.size());

	for (int i = 0; i < TMP.size(); i++) {
		TMP[i] = i;
	}

	for (int i = 0; i < POS.size(); i++) {
		MAP[POS[i]] = i;
	}



	for (auto j : POS) {
		BFS(j);
	}

	for (int i = 0; i < POS.size(); i++) {
		cout << POS[i].first << " " << POS[i].second << endl;
	}

	int DISTANCE = -1;
	do {
		int total = 0;
		total += DIST[s][e][POS[TMP[0]].first][POS[TMP[0]].second];
		for (int i = 0; i < int(TMP.size() - 1); i++) {
			cout << TMP[i] << " ";
			total += DIST[POS[TMP[i]].first][POS[TMP[i]].second][POS[TMP[i + 1]].first][POS[TMP[i + 1]].second];
		}
		cout << total << endl;
		if (DISTANCE == -1 || total < DISTANCE) {
			DISTANCE = total;
		}
	} while (next_permutation(TMP.begin(), TMP.end()));
	cout << "ANSWER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << DISTANCE << endl;
	














	return 0;
}