#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;
vector<int> T;
int path[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		path[index] = T[i];
		go(index + 1, n, m);
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	T.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		if (A[i - 1] != A[i]) {
			T.push_back(A[i]);
		}
	}
	
	go(0, T.size(), M);














	return 0;
}