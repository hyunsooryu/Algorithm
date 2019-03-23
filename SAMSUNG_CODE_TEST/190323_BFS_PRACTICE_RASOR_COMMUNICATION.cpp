//https://www.acmicpc.net/problem/6087
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N, M;

int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };


string A[100];
int D[100][100];
int C[100][100];
bool V[100][100];
bool isPossiblePos(int i, int j) {
	return (i >= 0 && j >= 0 && i < N && j < M) && (A[i][j] != '*') && V[i][j] == false;
}


pair<int, int> S = make_pair(-1, -1);
pair<int, int> E = make_pair(-1, -1);

void BFS(pair<int,int> N) {
	queue<pair<int, int>> Q;
	D[N.first][N.second] = 0;
	C[N.first][N.second] = 0;
	V[N.first][N.second] = true;
	Q.push(N);
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();

		int i = tmp.first;
		int j = tmp.second;

		if (i == E.first && j == E.second) {
			cout << D[i][j] - 1 << endl;
			break;
		}


		for (int k = 0; k < 4; k++) {
			int ni = i;
			int nj = j;
			int si = di[k];
			int sj = dj[k];
			while (true) {
				if (isPossiblePos(ni + si, nj + sj)) {
					D[ni + si][nj + sj] = D[i][j] + 1;
					C[ni + si][nj + sj] = D[i][j] + 1;
					V[ni + si][nj + sj] = true;
					Q.push(make_pair(ni + si, nj + sj));
					si += di[k];
					sj += dj[k];
				}
				else {
					break;
				}
			}
		}

		
	}

}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 'C') {
				if (S.first == -1) {
					S.first = i;
					S.second = j;
				}
				else {
					E.first = i;
					E.second = j;
				}
			}
		}
	}
	BFS(S);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (C[i][j] == 0) {
				cout << 0;
			}
			else {
				cout << C[i][j] - 1;
			}
		}
		cout << endl;
	}

	




	








	return 0;
}