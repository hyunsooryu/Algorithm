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
	bool operator()(const pair<int,int>& A, const pair<int,int>& B)const{
		return A.second > B.second;
	}
};


int BFSwithDeQ(int N, int M) {
	deque<pair<int, int>> DEQ;
	auto tmp = make_pair(1, 1);
	V[1][1] = true;
	DEQ.push_back(tmp);
	while (!DEQ.empty()) {
		auto temp = DEQ.front();
		DEQ.pop_front();

		int i = temp.first;
		int j = temp.second;
		cout << "POS : " << i << " " << j << " : " << A[i][j] << endl;
		cout << "D[" << i << "][" << j << "] : " << D[i][j] << endl;
		if (i == N && j == M) {
			return D[i][j];
		}

		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (possiblePos(ni, nj)) {
				V[ni][nj] = true;
				if (A[ni][nj] == 0) {
					D[ni][nj] += D[i][j];
					DEQ.push_front(make_pair(ni, nj));
				}
				else if(A[ni][nj] == 1){
					D[ni][nj] = D[i][j] + 1;
					DEQ.push_back(make_pair(ni, nj));
				}
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

	cout << BFSwithDeQ(N, M) << endl;














	return 0;
}
