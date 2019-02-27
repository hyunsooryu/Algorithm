#include "pch.h"
#include <iostream>

using namespace std;

int P[101];

//UnionFind

int Find(int N) {
	if (P[N] == N) {
		return N;
	}
	int tmp = Find(P[N]);
	return P[N] = tmp;
}

void Union(int S1, int S2) {
	P[Find(S2)] = Find(S1);
}

int N, M; // N : number of Computer / M : number of Network line


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		P[i] = i;
	}
	while (M--) {
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}

	int cnt = 0;
	int target = Find(1);
	for (int i = 2; i <= N; i++) {
		if (Find(i) == target) {
			cnt += 1;
		}
	}
	cout << cnt << endl;

	return 0;
}
