#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int N;
int V[100][100];
int A[100][100];
int G[100][100];
int Group_num = 1;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1,-1 };

int D[100][100];

queue<pair<int, int>> Q; //this Q is for BFS

void SetGroupByDFS(int i, int j) {
	D[i][j] = 1;
	Q.push(make_pair(i, j));
	cout << i << " " << j << " WAS PUSHED" << endl;
	for (int k = 0; k < 4; k++) {
		int ni = di[k] + i;
		int nj = dj[k] + j;
		if (ni >= 0 && nj >= 0 && ni < N && nj < N) {
			if (G[ni][nj] == 0 && A[ni][nj] == 1) {
				G[ni][nj] = G[i][j];
				SetGroupByDFS(ni, nj);
			}
		}
	}
}


int BFS() {
	int ans = 0;
	bool flag = false;

	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int i = tmp.first;
		int j = tmp.second;
		cout << i << "   " << j << endl;
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			cout << ni << " " << nj << endl;
			if (ni >= 0 && nj >= 0 && ni < N && nj < N){
				//check for end
				if (D[ni][nj] == 0) {
					G[ni][nj] = G[i][j];
					D[ni][nj] = D[i][j] + 1;
					Q.push(make_pair(ni, nj));
				}
				else {
					if (G[ni][nj] != G[i][j]) {
						ans = D[i][j] + D[ni][nj];
						flag = true;
						break;
					}
					else {
						continue;
					}
				}
			}
		}
		if (flag == true) {
			break;
		}
	}
	return ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (G[i][j] == 0 && A[i][j] == 1) {
				G[i][j] = Group_num++;
				SetGroupByDFS(i, j);
			}
		}
	}

	cout << " I AM A D " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << D[i][j] << " ";
		}
		cout << endl;
	}
	cout << "____________________________" << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}

	cout << "________________________________" << endl;


	cout << BFS() - 2 << endl;
	



	











	return 0;
}