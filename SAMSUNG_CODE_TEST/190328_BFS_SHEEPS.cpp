#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int N, M;
char A[250][250];
int wolfs;
int sheeps;
bool V[250][250];
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,-1,1 };
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 'v') {
				wolfs++;
			}
			else if (A[i][j] == 'o') {
				sheeps++;
			}
		}
	}

	cout << wolfs << " " << sheeps << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!V[i][j] && (A[i][j] != '#')) {
				[&](int i, int j, int& wolfs, int& sheeps) {
					int wolf = 0;
					int sheep = 0;
					queue<pair<int, int>> Q;
					V[i][j] = true;
					Q.push(make_pair(i, j));
					while (!Q.empty()) {
						auto tmp = Q.front();
						int pos_i = tmp.first;
						int pos_j = tmp.second;
						Q.pop();
						cout << pos_i << " " << pos_j << endl;
						if (A[pos_i][pos_j] == 'o') {
							sheep += 1;
						}
						else if (A[pos_i][pos_j] == 'v') {
							wolf += 1;
						}
						
						for (auto k = 0; k < 4; k++) {
							auto ni = di[k] + pos_i;
							auto nj = dj[k] + pos_j;
							if (ni >= 0 && nj >= 0 && ni < N && nj < M && !V[ni][nj] && A[ni][nj] != '#') {
								V[ni][nj] = true;
								Q.push(make_pair(ni, nj));
							}
						}
					}
					cout << wolf << " 는 늑대의 수" << endl;
					cout << sheep << " 은 양의 개수 " << endl;
					if (wolf >= sheep) {
						sheeps -= sheep;
					}
					else if (sheep > wolf) {
						wolfs -= wolf;
					}
				}(i, j, wolfs, sheeps);
			}
		}
	}
	cout << "ANSWER_______________________" << endl;
	cout << sheeps << " " << wolfs << endl;
	cout << "_____________________________" << endl;



	return 0;
}