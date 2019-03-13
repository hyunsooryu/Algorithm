#include "pch.h"
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int D[100001];
int P[100001];
//#3_ways
// X - 1
// X + 1
// X * 2
int Cal1[] = {-1, +1};

int start_position;
int target_position;
bool possible(int N) {
	return N >= 0 && N <= 100000 && D[N] == 0;
}

bool BFS(int N, int E) {
	queue<int> Q;
	D[N] = 1;
	Q.push(N);
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		if (tmp == E) {
			return true;
		}
		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				if (possible(tmp * 2)) {
					D[tmp * 2] = D[tmp] + 1;
					P[tmp * 2] = tmp;
					Q.push(tmp * 2);
				}
			}
			else {
				int target = tmp - Cal1[i];
				if (possible(target)) {
					D[target] = D[tmp] + 1;
					P[target] = tmp;
					Q.push(target);
				}
			}
		}
	}
	return false;
}

void PathFinder(int N) {
	if (P[N] == -1) {
		cout << N << " ";
		return;
	}
	PathFinder(P[N]);
	cout << N << " ";
}

int main() {
	fill(P, P + 100001, -1);
	cin >> start_position >> target_position;
	if (BFS(start_position, target_position)) {
		PathFinder(target_position);
	}

	return 0;
}