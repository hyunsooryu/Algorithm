#include "pch.h"
#include<iostream>
#include <queue>
using namespace std;
int V[1000][1000][2];
int A[1000][1000];
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
//2가지 경우가 존재하게 된다.
//1. 벽을 부셔서 들어온 경우.
//2. 벽을 부시지 않아서 들어온 경우.
//3. 어떤 경우든 최단거리이기만 하면된다.
//4. 결국 벽을 부셨는지 안 부셨는지 의 정보가 들어가야한다
// 결국 같은 칸이라해도, 할 수 있는 선택이 다르다. 그렇다면 다른 정점이다.
//벽을 부시고 들어온 것일수도있고, 벽을 부시지 않고 들어온것도 있기때문입니다.
//그렇기 때문에, 3차원배열을 사용해서 이를 표현해줍니다.
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}
	memset(V, -1, sizeof(V));
	queue<pair<pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(0, 0), 0));
	V[0][0][0] = 0;
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int i = tmp.first.first;
		int j = tmp.first.second;
		int flag = tmp.second; //벽을 부신적이 있는지 없는지에 대한 여부
		cout << i << " " << j << " " << flag << endl;
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
				if (flag == 1) { //내가 벽을 부시고 왔다면, 이미 벽을 부신적있는경우 벽은 못간다.
					if (A[ni][nj] == 0 && V[ni][nj][1] == -1) {
						V[ni][nj][1] = V[i][j][flag] + 1;
						Q.push(make_pair(make_pair(ni, nj), 1));
					}
				}
				else { //내가 아직 벽을 부시고 오지않았다면, 
					if (A[ni][nj] == 0 && V[ni][nj][0] == -1) { //방문하지 않은 통로의 경우 그냥갈수있고
						V[ni][nj][0] = V[i][j][flag] + 1;
						Q.push(make_pair(make_pair(ni, nj), 0));
					}
					else if (A[ni][nj] == 1 && V[ni][nj][1] == -1) { //방문하지 않은 벽의 경우 벽을 부시고는 갈수있다.
						V[ni][nj][1] = V[i][j][flag] + 1;
						Q.push(make_pair(make_pair(ni, nj), 1));
					}		
				}
			}
		}


	}
	int ans = -1;
	for (int i = 0; i < 2; i++) {
		if ((ans == -1) || (V[N - 1][M - 1][i] < ans)) {
			ans = V[N - 1][M - 1][i];
		}
	}
	if (ans == -1) {
		cout << ans << endl;
	}
	else {
		cout << ans + 1 << endl;
	}

	












	return 0;
}