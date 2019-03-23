//https://www.acmicpc.net/problem/15654
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int A[8];
bool V[8];
vector<int> path;
void go(int i, int cnt, vector<int>& path) {
	if (cnt == M) {
		for (auto j : path) {
			cout << A[j] << " ";
		}
		cout << endl;
		return;
	}
	for (int j = 0; j < N; j++) {
		if (!V[j]) {
			V[j] = true;
			path.push_back(j);
			go(j, cnt + 1, path);
			path.pop_back();
			V[j] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);
	vector<int> path;
	for (int i = 0; i < N; i++) {
		V[i] = true;
		path.push_back(i);
		go(i, 1, path);
		path.pop_back();
		V[i] = false;
	}

	













	return 0;
}