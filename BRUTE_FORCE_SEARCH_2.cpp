#include "pch.h"
#include <iostream>

using namespace std;

int N, M;
int S, E;
int A[100001];


int Solve() {
	int size = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int S = 0;
	int E = 0;
	int sum = 0;
	while (S <= E && E < N) {
		if (sum < M) {
			sum += A[E++];
		}
		else if (sum >= M) {
			if (size == 0 || E - S < size) {
				size = E - S;
			}
			sum -= A[S++];
		}
		else {
			if (size == 0 || E - S < size) {
				size = E - S;
			}
			sum += A[E++];
		}
	}
	return size;
}

int main() {

	cout << Solve() << endl;










	return 0;
}
