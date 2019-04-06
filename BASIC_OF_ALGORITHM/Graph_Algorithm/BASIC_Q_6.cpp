//BFS 비버의 굴 조금 어려운 문제지만, 경우의수를 잘 따져서 풀어낼 수 있다.
#include <iostream>
#include <queue>
using namespace std;
int N, M;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
char A[50][50];
int V[50][50];
int P[50][50];

pair<int, int> S;
pair<int, int> D;
queue<pair<int, int>> Q;
int main() {
	memset(V, -1, sizeof(V));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 'D') {
				D = make_pair(i, j);
			}
			else if (A[i][j] == 'S') {
				S = make_pair(i, j);
			}
			else if (A[i][j] == '*') {
				V[i][j] = 0;
				P[i][j] = 2; //water
				Q.push(make_pair(i, j));
			}
		}
	}

	V[S.first][S.second] = 0;
	P[S.first][S.second] = 1; //animal
	Q.push(S);

	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int i = tmp.first;
		int j = tmp.second;
		int type = P[i][j];
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (ni >= 0 && nj >= 0 && ni < N && nj < M && V[ni][nj] == -1) {
				if (type == 1) {
					if (P[ni][nj] == 0 && A[ni][nj] != 'X' && A[ni][nj] != '*') {
						V[ni][nj] = V[i][j] + 1;
						P[ni][nj] = type;
						Q.push(make_pair(ni, nj));
					}
				}
				else {
					if (P[ni][nj] == 0 && A[ni][nj] == '.') {
						V[ni][nj] = V[i][j] + 1;
						P[ni][nj] = type;
						Q.push(make_pair(ni, nj));
					}
				}
			}
		}
	}

	if (P[D.first][D.second] == 1) {
		cout << V[D.first][D.second] << endl;
	}
	else {
		cout << "KAKTUS" << endl;
	}












	return 0;
}