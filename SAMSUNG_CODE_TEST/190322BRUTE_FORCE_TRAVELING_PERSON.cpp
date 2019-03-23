#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[10][10];
int B[10];

int calculation() {
	int sum = 0;
	if (A[0][B[1]] == 0) { 
		return -1;
	}
	sum += A[0][B[1]];
	for (int i = 1; i < N - 1; i++) {
		if (A[B[i]][B[i + 1]] == 0) {
			return -1;
		}
		sum += A[B[i]][B[i + 1]];
	}
	if (A[B[N - 1]][0] == 0) {
		return -1;
	}
	sum += A[B[N - 1]][0];
	return sum;
}
int MIN = -1;
int main() {
	cin >> N;
	int t = 0;
	for_each(B, B + N, [&](int& nVal) {nVal = t++; });
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	do {
		int tmp = calculation();
		cout << tmp << endl;
		if (tmp > 0) {
			if (MIN == -1 || tmp < MIN) {
				MIN = tmp;
			}
		}
		for (int i = 0; i < N; i++) {
			cout << B[i] << " ";
		}
		cout << endl;
	} while (next_permutation(B + 1, B + N));

	cout << MIN << endl;







	return 0;
}