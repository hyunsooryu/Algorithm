//DEQUE BFS
//DEQUE을 이용하면 , BFS탐색에 있어서도 그 탐색의 우선순위를 정해낼 수있다는 장점이있습니다.
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int A[100][100];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
int V[100][100];
int main() {
	//ALGOSPOT 벽 부시는것을 최소화 해야합니다. 벽이 아닌곳을 넣을때는 FRONT / 벽인곳은 BACK
	int N, M;
	cin >> M >> N;
	int target_n = N - 1;
	int target_m = M - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}

	memset(V, -1, sizeof(V));

	deque<pair<int, int>> Q;
	V[0][0] = 0;
	Q.push_back(make_pair(0, 0));
	while (!Q.empty()) {
		auto tmp = Q.front();
		int i = tmp.first;
		int j = tmp.second;
		Q.pop_front();
		if (i == target_n && j == target_m) {
			cout << V[i][j];
			break;
		}
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni >= 0 && nj >= 0 && ni < N && nj < M && V[ni][nj] == -1) {
				if (A[ni][nj] == 0) {
					V[ni][nj] = V[i][j];
					Q.push_front(make_pair(ni, nj));
				}
				else {
					V[ni][nj] = V[i][j] + 1;
					Q.push_back(make_pair(ni, nj));
				}
			}
		}
	}


	
	












	return 0;
}