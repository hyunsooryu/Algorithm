#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
//key

int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
int TEST_CASE;
int main() {
	cin >> TEST_CASE;
	while (TEST_CASE--) {
		int R;
		int C;
		int N, M;
		string A[102];
		map <pair<pair<int, int>, vector<char>>, bool> V;
		int SCORES = 0;
		string keeys;
		cin >> N >> M;
		R = N + 1;
		C = M + 1;
		//MAP_SETTING
		for (int i = 1; i <= N; i++) {
			A[i].push_back('.');
			string x;
			cin >> x;
			A[i] += x;
			A[i] += '.';
		}
		cin >> keeys;
		for (int i = 0; i < M + 2; i++) {
			A[0] += '.';
			A[N + 1] += '.';
		}

		vector<char> key;
		if (keeys != "0") {
			for (auto j : keeys) {
				key.push_back(j);
			}
		}
		queue<pair<pair<int, int>, vector<char>>> Q;
		V[make_pair(make_pair(0, 0), key)] = true;
		Q.push(make_pair(make_pair(0, 0), key));
		while (!Q.empty()) {
			auto top = Q.front();
			auto Keys = top.second;
			auto i = top.first.first;
			auto j = top.first.second;
			Q.pop();
			//cout << i << " - " << j << " VISITED : " << " KEYS STATUS : ";
			for (auto t : Keys) {
				//cout << t << " ";
			}
			if (A[i][j] == '$') {
				//cout << "map Find!" << " ";
				SCORES += 1;
			}
			//cout << endl;

			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (ni < 0 || ni > R || nj < 0 || nj > C) {
					continue;
				}

				if (A[ni][nj] == '.') {
					if (V[make_pair(make_pair(ni, nj), Keys)] == false) {
						V[make_pair(make_pair(ni, nj), Keys)] = true;
						Q.push(make_pair(make_pair(ni, nj), Keys));
					}
				}
				else if (A[ni][nj] >= 'a' && A[ni][nj] <= 'z') {
					auto flag = false;
					if (find(Keys.begin(), Keys.end(), A[ni][nj]) == Keys.end()) {
						flag = true;
					}

					if (flag) {
						auto tmpKeys = Keys;
						tmpKeys.push_back(A[ni][nj]);
						sort(tmpKeys.begin(), tmpKeys.end());
						V[make_pair(make_pair(ni, nj), tmpKeys)] = true;
						Q.push(make_pair(make_pair(ni, nj), tmpKeys));
					}
					else {
						if (V[make_pair(make_pair(ni, nj), Keys)] == false) {
							V[make_pair(make_pair(ni, nj), Keys)] = true;
							Q.push(make_pair(make_pair(ni, nj), Keys));
						}
					}
				}
				else if (A[ni][nj] >= 'A' && A[ni][nj] <= 'Z') {
					if (find(Keys.begin(), Keys.end(), char(tolower(A[ni][nj]))) != Keys.end()) {
						if (V[make_pair(make_pair(ni, nj), Keys)] == false) {
							V[make_pair(make_pair(ni, nj), Keys)] = true;
							Q.push(make_pair(make_pair(ni, nj), Keys));
						}
					}
				}
				else if (A[ni][nj] == '$') {
					if (V[make_pair(make_pair(ni, nj), Keys)] == false) {
						V[make_pair(make_pair(ni, nj), Keys)] = true;
						Q.push(make_pair(make_pair(ni, nj), Keys));
					}
				}
			}
		}

		cout << SCORES << endl;
	}

	return 0;
}

/*
3
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
5 11
*.*********
*...*...*x*
*X*.*.*.*.*
*$*...*...*
***********
0
7 7
*ABCDE*
X.....F
W.$$$.G
V.$$$.H
U.$$$.J
T.....K
*SQPML*
irony

*/