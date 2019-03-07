#include "pch.h"
#include <iostream>

using namespace std;

//HOW MANY CYCLES ARE IN GRAPH?
bool V[1001];
int A[1001];
int T;

int DFS(int i) {
	V[i] = true;
	if (!V[A[i]]) {
		return DFS(A[i]);
	}
	return 1;
}
int main() {
	cin >> T;
	while (T--) {
		memset(V, false, sizeof(V));
		int M;
		cin >> M;
		for (int i = 1; i <= M; i++) {
			int x;
			cin >> x;
			A[i] = x;
		}
		auto total = 0;
		for (int i = 1; i <= M; i++) {
			if (!V[i]) {
				total += DFS(i);
			}
		}
		cout << total << endl;
	}










	return 0;
}