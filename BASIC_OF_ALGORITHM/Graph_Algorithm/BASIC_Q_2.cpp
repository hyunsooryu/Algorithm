#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//단지 번호 붙이기 좌우위아래로 집이 있는경우 연결되어있다.
//연결요소의 개수를 찾는것과 상당히 유사한 문제입니다.
int A[25][25]; //단지
int V[25][25]; //단지 번호
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
int N;
vector<int> ans;
void DFS(int i, int j, int num, int& t) {
	V[i][j] = num;
	t += 1;
	for (int k = 0; k < 4; k++) {
		int ni = di[k] + i;
		int nj = dj[k] + j;
		if (ni >= 0 && nj >= 0 && ni < N && nj < N && V[ni][nj] == 0 && A[ni][nj] == 1) {
			DFS(ni, nj, num, t);
		}
	}
}
int main() {
	cin >> N;
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (V[i][j] == 0 && A[i][j] == 1) {
				int t = 0;
				DFS(i, j, num, t);
				ans.push_back(t);
				num += 1;
			}
		}
	}

	cout << num - 1 << endl;
	sort(ans.begin(), ans.end());
	for (auto j : ans) {
		cout << j << " ";
	}
	cout << endl;









	return 0;
}