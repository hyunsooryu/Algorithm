#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int SIZE;
bool V[10001];
vector<int> path;
vector<int> A;
void go(int i, int cnt) {
	if (cnt == M) {
		for (auto j : path) {
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	for (int j = i; j < SIZE; j++) {
		path.push_back(A[j]);
		go(j, cnt + 1);
		path.pop_back();
	}

}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (V[x]) {
			continue;
		}
		V[x] = true;
		A.push_back(x);
	}
	sort(A.begin(), A.end());
	SIZE = A.size();
	
	for (int i = 0; i < SIZE; i++) {
		path.push_back(A[i]);
		go(i, 1);
		path.pop_back();
	}

	return 0;
}