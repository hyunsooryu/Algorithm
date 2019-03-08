#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int N, M;

map<vector<int>, bool> MAP;
vector<int> path;
void go(int i, int cnt) {
	if (cnt == 3) {
		for (auto j : path) {
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	for (int k = i; k <= N; k++) {
		path.push_back(k);
		go(k, cnt + 1);
		path.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		path.push_back(i);
		go(i, 1);
		path.pop_back();
	}

	return 0;
}