//조금 더 좋은 풀이
/*
일단 물을 다 뿌려놓은 후에, 그리고 문제를 풀어간다.
*/
#include <iostream>
#include <queue>
//NEW IDEA 동시에 BFS를 구현시키는것은 번거롭다!!
using namespace std;
int N, M;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
char A[50][50];
int V[50][50];
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
				Q.push(make_pair(i, j));
			}
		}
	}
	//물을 먼저 다 채웁니다.
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + tmp.first;
			int nj = dj[k] + tmp.second;
			if (ni >= 0 && nj >= 0 && ni < N && nj < M && V[ni][nj] == -1 && A[ni][nj] != 'X' && A[ni][nj] != 'D') {
				V[ni][nj] = V[tmp.first][tmp.second] + 1;
				Q.push(make_pair(ni, nj));
			}
		}
	}
	V[S.first][S.second] = 0;
	Q.push(S);
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + tmp.first;
			int nj = dj[k] + tmp.second;
			if ((ni >= 0 && nj >= 0 && ni < N && nj < M) && (V[ni][nj] > V[tmp.first][tmp.second] + 1 || V[ni][nj] == -1) && (A[ni][nj] != 'X' && A[ni][nj] != '*')) {
				V[ni][nj] = V[tmp.first][tmp.second] + 1;
				Q.push(make_pair(ni, nj));
			}
		}
	}

	if (V[D.first][D.second] == -1) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << V[D.first][D.second] << endl;
	}













	return 0;
}