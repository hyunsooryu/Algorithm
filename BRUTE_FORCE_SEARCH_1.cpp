#include "pch.h"
#include <iostream>

using namespace std;

int S = -1;
int E = -1;
int N, M;
int A[100001];
int cnt = 0;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int sum = 0;
	while (S < N && E < N) {
		if (sum == M) {
			for (int i = S + 1; i <= E; i++) {
				cout << A[i] << " ";
			}
			cout << endl;
			cnt += 1;
			E += 1;
			if (E < N) {
				sum += A[E];
			}
		}
		if (sum < M) {
			E += 1;
			if (E < N) {
				sum += A[E];
			}
		}
		else if (sum > M) {
			S += 1;
			if (S < N) {
				sum -= A[S];
			}
		}
	}

	cout << cnt << endl;






	return 0;
}
