#include "pch.h"
#include <iostream>
using namespace std;
int N, M;
int A[501][501];
int MAX = 0;
//1 * 4
void OneToFour(int x, int y) {
	if (y + 3 > M) {
		return;
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += A[x][y + i];
	}
	if (sum > MAX) {
		MAX = sum;
	}
}
//4 * 1
void FourToOne(int x, int y) {
	if (x + 3 > N) {
		return;
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += A[x + i][y];
	}
	if (sum > MAX) {
		MAX = sum;
	}
}

// 3 * 2
void ThreeToTwo(int x, int y) {
	if (x + 2 > N || y + 1 > M) {
		return;
	}
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			sum += A[x + i][y + j];
		}
	}
	//first
	if (sum - (A[x][y] + A[x + 2][y]) > MAX) {
		MAX = sum - (A[x][y] + A[x + 2][y]);
	}
	if (sum - (A[x][y + 1] + A[x + 2][y + 1]) > MAX) {
		MAX = sum - (A[x][y + 1] + A[x + 2][y + 1]);
	}
	//second
	if (sum - (A[x][y] + A[x + 1][y]) > MAX) {
		MAX = sum - (A[x][y] + A[x + 1][y]);
	}
	if (sum - (A[x][y + 1] + A[x + 1][y + 1]) > MAX) {
		MAX = sum - (A[x][y + 1] + A[x + 1][y + 1]);
	}
	if (sum - (A[x + 1][y] + A[x + 2][y]) > MAX) {
		MAX = sum - (A[x + 1][y] + A[x + 2][y]);
	}
	if (sum - (A[x + 1][y + 1] + A[x + 2][y + 1]) > MAX) {
		MAX = sum - (A[x + 1][y + 1] + A[x + 2][y + 1]);
	}
	//third
	if (sum - (A[x][y] + A[x + 2][y + 1]) > MAX) {
		MAX = sum - (A[x][y] + A[x + 2][y + 1]);
	}
	if (sum - (A[x][y + 1] + A[x + 2][y]) > MAX) {
		MAX = sum - (A[x][y + 1] + A[x + 2][y]);
	}
}
//2 * 3
void TwoToThree(int x, int y) {
	if (x + 1 > N || y + 2 > M) {
		return;
	}
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			sum += A[x + i][y + j];
		}
	}
	//first
	if (sum - (A[x][y] + A[x][y + 2]) > MAX) {
		MAX = sum - (A[x][y] + A[x][y + 2]);
	}
	if (sum - (A[x + 1][y] + A[x + 1][y + 2]) > MAX) {
		MAX = sum - (A[x + 1][y] + A[x + 1][y + 2]);
	}
	//second;
	if (sum - (A[x][y] + A[x][y + 1]) > MAX) {
		MAX = sum - (A[x][y] + A[x][y + 1]);
	}
	if (sum - (A[x][y + 1] + A[x][y + 2]) > MAX) {
		MAX = sum - (A[x][y + 1] + A[x][y + 2]);
	}
	if (sum - (A[x + 1][y] + A[x + 1][y + 1]) > MAX) {
		MAX = sum - (A[x + 1][y] + A[x + 1][y + 1]);
	}
	if (sum - (A[x + 1][y + 1] + A[x + 1][y + 2]) > MAX) {
		MAX = sum - (A[x + 1][y + 1] + A[x + 1][y + 2]);
	}
	//third;
	if (sum - (A[x][y] + A[x + 1][y + 2]) > MAX) {
		MAX = sum - (A[x][y] + A[x + 1][y + 2]);
	}
	if (sum - (A[x + 1][y] + A[x][y + 2]) > MAX) {
		MAX = sum - (A[x + 1][y] + A[x][y + 2]);
	}
}
// 2 * 2
void TwoToTwo(int x, int y) {
	if (x + 1 > N || y + 1 > M) {
		return;
	}
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sum += A[x + i][y + j];
		}
	}
	if (sum > MAX) {
		MAX = sum;
	}
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			OneToFour(i, j);
			FourToOne(i, j);
			ThreeToTwo(i, j);
			TwoToThree(i, j);
			TwoToTwo(i, j);
			cout << MAX << endl;
		}
	}

	cout << MAX << endl;











	return 0;
}