#include "pch.h"
#include <iostream>

using namespace std;
int N;
int Cal[4];
int A[11];
long long MAX = -1000000000;
long long MIN = 1000000000;

bool possible(long long N) {
	if (N <= 1000000000 && N >= -1000000000) {
		return true;
	}
	return false;
}

void go(int i, long long sum) {
	if (i == N) {
		if (sum > MAX) {
			MAX = sum;
		}
		if (sum < MIN) {
			MIN = sum;
		}
		return;
	}
	// +
	if (Cal[0] > 0 && possible(sum + A[i])) {
		Cal[0] -= 1;
		go(i + 1, sum + A[i]);
		Cal[0] += 1;
	}
	// -
	if (Cal[1] > 0 && possible(sum - A[i])) {
		Cal[1] -= 1;
		go(i + 1, sum - A[i]);
		Cal[1] += 1;
	}
	// *
	if (Cal[2] > 0 && possible(sum * A[i])) {
		Cal[2] -= 1;
		go(i + 1, sum * A[i]);
		Cal[2] += 1;
	}
	// /
	if (Cal[3] > 0 && possible(sum / A[i])) {
		Cal[3] -= 1;
		go(i + 1, sum / A[i]);
		Cal[3] += 1;
	}
	return;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int k = 0; k < 4; k++) {
		cin >> Cal[k];
	}

	go(1, A[0]);
	cout << MAX << endl;
	cout << MIN << endl;

	return 0;
}