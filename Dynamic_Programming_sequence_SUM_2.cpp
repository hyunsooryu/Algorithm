#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int D[100001][3];
int A[100001];


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	D[1][1] = A[1];
	for (int i = 2; i <= N;i++) {
		D[i][1] = A[i];
		if (D[i - 1][1] + A[i] > D[i][1]) {
			D[i][1] = D[i - 1][1] + A[i];
		}
		if (i >= 3) {
			D[i][2] = D[i - 2][1] + A[i];
			if (D[i - 1][2] + A[i] > D[i][2]) {
				D[i][2] = D[i - 1][2] + A[i];
			}
		}
	}

	int t_1 = *max_element(&D[1][1], &D[N + 1][1]);
	int t_2 = *max_element(&D[1][2], &D[N + 1][2]);

	cout << max(t_1, t_2) << endl;






	return 0;
}