#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int N;
int A[10][10];
const int INF = -1;
int D[10][(1 << 10) - 1];
int go(int i, int S) {
	cout << i << " " << S << endl;
	if (D[i][S] != 0) {
		return D[i][S];
	}
	if (S == 0) {
		if (A[i][0] > 0) {
			return D[i][S] = A[i][0];
		}
		else {
			return D[i][S] = INF;
		}
	}
	auto tmp = INF;
	for (int k = 1; k < N; k++) {
		if (A[i][k] > 0 && ((1 << k) & S)) {
			int remover = ~(1 << k);
			int new_S = S & remover;
			auto temp = go(k, new_S);
			if (temp > 0) {
				temp += A[i][k];
				if (temp < tmp || tmp == INF) {
					tmp = temp;
				}
			}
		}
	}
	return D[i][S] = tmp;
}


int main() {
	cin >> N;
	int S = (1 << N) - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	int remover = ~(1 << 0);
	int new_S = S & remover;
	int ans = go(0, new_S);
	cout << ans << endl;
















	return 0;
}