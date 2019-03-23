//https://www.acmicpc.net/problem/1261
#include <iostream>
#include <deque>
using namespace std;
//(1 ≤ N, M ≤ 100) //PRIORITY_QUEUE OR DEQUE 
deque <pair<int, int>> DEQ;
int N, M;
int A[101][101];
int D[101][101]; //벽을 뿌신 횟수.
bool V[101][101]; //방문 했는지의 여부.
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}
	D[1][1] = 0;
	V[1][1] = true;
	DEQ.push_back(make_pair(1, 1));
	while (!DEQ.empty()) {
		auto tmp = DEQ.front();
		DEQ.pop_front();

		int i = tmp.first;
		int j = tmp.second;
		cout << i << " " << j << endl;

		if (i == N && j == M) {
			cout << D[N][M] << endl;
			break;
		}
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (ni >= 1 && nj >= 1 && ni <= N && nj <= M && !V[ni][nj]) {
				if (A[ni][nj] == 1) {
					D[ni][nj] = D[i][j] + 1;
					V[ni][nj] = true;
					DEQ.push_back(make_pair(ni, nj));
				}
				else {
					D[ni][nj] = D[i][j];
					V[ni][nj] = true;
					DEQ.push_front(make_pair(ni, nj));
				}
			}
		}

	}










	return 0;
}