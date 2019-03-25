#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
char A[1500][1500];
int N, M;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
int D[1500][1500];
int P[1500][1500];
bool isPossible(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

deque<pair<int, int>> DEQ;
pair<int, int> b1;
pair<int, int> b2;
int main() {
	b1.first = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '.') {
				DEQ.push_back(make_pair(i, j));
			}
			else if (A[i][j] == 'L') {
				if (b1.first == -1) {
					P[i][j] = 1;
					D[i][j] = 1;
					b1.first = i; b1.second = j;
				}
				else {
					P[i][j] = 2;
					D[i][j] = 1;
					b2.first = i; b2.second = j;
				}
				DEQ.push_back(make_pair(i, j));
			}
		}
	}

	int ans = 0;
	while (!DEQ.empty()) {

		auto tmp = DEQ.front();
		DEQ.pop_front();
		int i = tmp.first;
		int j = tmp.second;
		int id = P[i][j];
		auto flag = false;
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (!isPossible(ni, nj)) {
				continue;
			}
			if (id == 0) {//물
				if (A[ni][nj] == 'X') {
					A[ni][nj] = '.';
					DEQ.push_back(make_pair(ni, nj));
				}
			}
			else if (id == 1 || id == 2) {
				if (A[ni][nj] == '.') {
					A[ni][nj] = 'L';
					P[ni][nj] = id;
					D[ni][nj] = D[i][j];
					DEQ.push_front(make_pair(ni, nj));
				}
				else if(A[ni][nj] == 'X'){
					A[ni][nj] = 'L';
					P[ni][nj] = id;
					D[ni][nj] = D[i][j] + 1;
					DEQ.push_back(make_pair(ni, nj));
				}
				else {
					if (P[ni][nj] == id) {
						continue;
					}
					else {
						ans = max(D[ni][nj], D[i][j]);
						flag = true;
						break;
					}
				}
			}
		}
		if (flag) {
			cout << ans << endl;
			break;
		}
	}

	















	return 0;
}