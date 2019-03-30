#include "pch.h"
#include <iostream>
#include <queue>
#include <set>

using namespace std;
int N, M;
int MAX_ROOM = 0;
char A[200][200];
bool V[200][200];
int D[200][200];
vector<int> ROOM;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int MAX = 0;
set<int> closer_room[2500];
void BFS(int i, int j, int room_num) {
	int cnt = 0;
	V[i][j] = true;
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));
	while(!Q.empty()){
		auto tmp = Q.front();
		Q.pop();
		if (A[tmp.first][tmp.second] == 'O') {
			cnt += 1;
			D[tmp.first][tmp.second] = room_num;
		}
		cout << tmp.first << " " << tmp.second << endl;
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + tmp.first;
			int nj = dj[k] + tmp.second;
			if (ni >= 0 && nj >= 0 && ni < N * 2 + 1 && nj < M * 2 + 1 && A[ni][nj] != 'X' && V[ni][nj] == false) {
				V[ni][nj] = true;
				Q.push(make_pair(ni, nj));
				
			}
		}
	}
	ROOM.push_back(cnt);
	if (cnt > MAX) {
		MAX = cnt;
	}
}

void BFS_R(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));
	V[i][j] = true;
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		for (int p = 0; p < 4; p++) {
			int ni = di[p] + tmp.first;
			int nj = dj[p] + tmp.second;
			if (ni >= 0 && nj >= 0 && ni < N * 2 + 1 && nj < M * 2 + 1 && A[ni][nj] != 'X' && V[ni][nj] == false) {
				V[ni][nj] = true;
				Q.push(make_pair(ni, nj));
			}
			if (ni >= 0 && nj >= 0 && ni < N * 2 + 1 && nj < M * 2 + 1 && A[ni][nj] == 'X') {
				for (int k = 0; k < 4; k++) {
					int ti = di[k] + ni;
					int tj = dj[k] + nj;
					if (ti >= 0 && tj >= 0 && ti < N * 2 + 1 && tj < M * 2 + 1 && A[ti][tj] == 'O' && D[i][j] != D[ti][tj]) {
						cout << D[i][j] << " " << D[ti][tj] << endl;
						cout << "CANDIDATE!!!" << endl;
						cout << ROOM[D[ti][tj]] + ROOM[D[i][j]] << endl;
						if (ROOM[D[ti][tj]] + ROOM[D[i][j]] > MAX_ROOM) {
							MAX_ROOM = ROOM[D[ti][tj]] + ROOM[D[i][j]];
						}
					}
				}
			}
		}
	}
	cout << MAX_ROOM << endl;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			A[i][j] = 'X';
		}
	}
	for (int i = 1; i < N * 2 + 1; i += 2) {
		for (int j = 1; j < M * 2 + 1; j += 2) {
			int x;
			cin >> x;
			A[i][j] = 'O';
			if (x & 1) {
				A[i][j - 1] = 'X';
			}
			else {
				A[i][j - 1] = '.';
			}
			if (x & 2) {
				A[i - 1][j] = 'X';
			}
			else {
				A[i - 1][j] = '.';
			}
			if (x & 4) {
				A[i][j + 1] = 'X';
			}
			else {
				A[i][j + 1] = '.';
			}
			if (x & 8) {
				A[i + 1][j] = 'X';
			}
			else {
				A[i + 1][j] = '.';
			}
		}
	}
	for (int i = 0; i < N * 2 + 1; i++) {
		for (int j = 0; j < M * 2 + 1; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}
	int room_number = 0;
	for (int i = 0; i < N * 2 + 1; i++) {
		for (int j = 0; j < M * 2 + 1; j++) {
			if (V[i][j] == false && A[i][j] == 'O') {
				BFS(i, j, room_number);
				room_number += 1;
			}
		}
	}
	for (auto j : ROOM) {
		cout << j << " ";
	}
	cout << endl;

	cout << room_number << endl;
	cout << MAX << endl;
	memset(V, false, sizeof(V));
	for (int i = 0; i < N * 2 + 1; i++) {
		for (int j = 0; j < M * 2 + 1; j++) {
			if (V[i][j] == false && A[i][j] == 'O') {
				BFS_R(i, j);
			}
		}
	}
	

	cout << "ANSWER!!" << endl;
	cout << "방의 개수 : " << room_number << endl;
	cout << "방 중 넓은 방 : " << MAX << endl;
	cout << "방을 합쳤을 때 가장 넓은 방 : " << MAX_ROOM << endl;
	

	return 0;
}