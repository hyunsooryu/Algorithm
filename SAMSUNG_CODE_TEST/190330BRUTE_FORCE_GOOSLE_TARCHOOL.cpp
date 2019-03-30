#include "pch.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int N, M;
char A[10][10];
int D[10][10][10][10];
bool V[10][10][10][10];
pair<int, int> R;
pair<int, int> B;
pair<int, int> O;

int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

bool K0(pair<int,int> A, pair<int,int> B) {
	if (A.first < B.first) {
		return true;
	}
	else {
		return false;
	}
}
bool K1(pair<int, int> A, pair<int, int> B) {
	if (A.first > B.first) {
		return true;
	}
	return false;
}
bool K2(pair<int, int> A, pair<int, int> B) {
	if (A.second < B.second) {
		return true;
	}
	return false;
}
bool K3(pair<int, int> A, pair<int, int> B) {
	if (A.second > B.second) {
		return true;
	}
	return false;
}


pair<pair<int,int>, bool> getDestination(int pos_i, int pos_j, int ni, int nj) {
	int k = 0;
	int target_pos_i = pos_i;
	int target_pos_j = pos_j;
	int ki = ni;
	int kj = nj;
	while (true) {	
		target_pos_i += ki;
		target_pos_j += kj;
		if(A[target_pos_i][target_pos_j] == 'O') {
			return make_pair(make_pair(target_pos_i, target_pos_j), true);
		}
		else if (A[target_pos_i][target_pos_j] == '#') {
			return make_pair(make_pair(target_pos_i - ni, target_pos_j - nj), false);
			break;
		}
	}
}

int main(){
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 'R') {
				R.first = i;
				R.second = j;
			}
			else if (A[i][j] == 'B') {
				B.first = i;
				B.second = j;
			}
			else if (A[i][j] == 'O') {
				O.first = i;
				O.second = j;
			}
		}
	}

	V[R.first][R.second][B.first][B.second] = true;
	D[R.first][R.second][B.first][B.second] = 0;
	queue <pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(R, B));
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();

		auto red_pos_i = tmp.first.first;
		auto red_pos_j = tmp.first.second;
		auto blue_pos_i = tmp.second.first;
		auto blue_pos_j = tmp.second.second;

		cout << red_pos_i << "  " << red_pos_j << "  " << blue_pos_i << "  " << blue_pos_j << endl;

		for (int k = 0; k < 4; k++) {
			int ni = di[k];
			int nj = dj[k];
			auto tmp_RED = getDestination(red_pos_i, red_pos_j, ni, nj);
			auto tmp_BLUE = getDestination(blue_pos_i, blue_pos_j, ni, nj);
			if (tmp_RED.second == true && tmp_BLUE.second == true) {
				continue;
			}
			if(tmp_RED.first == tmp_BLUE.first) {
				cout << "WE ARE SAME!!" << endl;
				cout << tmp_RED.first.first << "  " << tmp_RED.first.second << "  " << tmp_BLUE.first.first << " " << tmp_BLUE.first.second << " ";
				cout << endl;
				cout << "!!!" << endl;
				if (k == 0) {
					auto flag = K0(tmp.first, tmp.second);
					cout << flag << " " << k << endl;
					if (flag) {
						tmp_BLUE.first.first -= ni;
						tmp_BLUE.first.second -= nj;
					}
					else {
						tmp_RED.first.first -= ni;
						tmp_RED.first.second -= nj;
					}
				}
				else if (k == 1) {
					auto flag = K1(tmp.first, tmp.second);
					cout << flag << " " << k << endl;
					if (flag) {
						tmp_BLUE.first.first -= ni;
						tmp_BLUE.first.second -= nj;
					}
					else {
						tmp_RED.first.first -= ni;
						tmp_RED.first.second -= nj;
					}
				}
				else if (k == 2) {
					auto flag = K2(tmp.first, tmp.second);
					cout << flag << " " << k << endl;
					if (flag) {
						tmp_BLUE.first.first -= ni;
						tmp_BLUE.first.second -= nj;
					}
					else {
						tmp_RED.first.first -= ni;
						tmp_RED.first.second -= nj;
					}
				}
				else {
					auto flag = K3(tmp.first, tmp.second);
					cout << flag << " " << k << endl;
					if (flag) {
						tmp_BLUE.first.first -= ni;
						tmp_BLUE.first.second -= nj;
					}
					else {
						tmp_RED.first.first -= ni;
						tmp_RED.first.second -= nj;
					}
				}
				cout << "I AM FIXED!!" << endl;
				cout << tmp_RED.first.first << "  " << tmp_RED.first.second << "  " << tmp_BLUE.first.first << " " << tmp_BLUE.first.second << " " << endl;
				if (!V[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second]) {
					V[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second] = true;
					D[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second] = D[red_pos_i][red_pos_j][blue_pos_i][blue_pos_j] + 1;
					Q.push(make_pair(make_pair(tmp_RED.first.first, tmp_RED.first.second), make_pair(tmp_BLUE.first.first, tmp_BLUE.first.second)));
				}
			}
			else {
				if (tmp_RED.second == true) {
					if (!V[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second]) {
						cout << "발견 !!! " << endl;
						cout << tmp_RED.first.first << " " << tmp_RED.first.second << endl;
						ans = D[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second] = D[red_pos_i][red_pos_j][blue_pos_i][blue_pos_j] + 1;
						cout << ans << endl;
						return 0;
					}
				}
				else if (tmp_BLUE.second == true) {
					continue;
				}
				else {
					if (!V[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second]) {
						V[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second] = true;
						D[tmp_RED.first.first][tmp_RED.first.second][tmp_BLUE.first.first][tmp_BLUE.first.second] = D[red_pos_i][red_pos_j][blue_pos_i][blue_pos_j] + 1;
						Q.push(make_pair(make_pair(tmp_RED.first.first, tmp_RED.first.second), make_pair(tmp_BLUE.first.first, tmp_BLUE.first.second)));
					}
				}
			}
		}

	}
	


	cout << -1 << endl;
	return 0;
}
