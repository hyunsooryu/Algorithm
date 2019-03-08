#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int N, M;
vector<int> path;
int A[10001];
bool imPossible[10001];

void go(int i, int cnt) {
	if (cnt == M) {
		for (auto j : path) {
			cout << A[j] << " ";
		}
		cout << endl;
		return;
	}
	sort(A + 1, A + N + 1);
	for (int k = 1; k <= N; k++) {
		if (imPossible[k]) {
			continue;
		}
		path.push_back(k);
		imPossible[k] = true;
		go(k, cnt + 1);
		path.pop_back();
		imPossible[k] = false;
	}
}

int main() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		path.push_back(i);
		imPossible[i] = true;
		go(i, 1);
		path.pop_back();
		imPossible[i] = false;
	}

	return 0;
}