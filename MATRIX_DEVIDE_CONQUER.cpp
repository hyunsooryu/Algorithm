#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int SIZE;
vector<vector<int>> BASIC;
int getMatrix(int i, int j, vector<vector<int>> A, vector<vector<int>> B) {
	auto tmp = 0;
	for (int k = 0; k < SIZE; k++) {
		tmp += A[i][k] * B[k][j];
	}
	return tmp % 1000;
}


vector<vector<int>> Calculate(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> tmp(SIZE);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tmp[i].push_back(getMatrix(i, j, A, B));
		}
	}
	return tmp;
}


vector<vector<int>> Go(int N){
	if (N == 1) {
		return BASIC;
	}
	if (N & 1) {
		auto tmp = Go((N - 1) / 2);
		tmp = Calculate(tmp, tmp);
		return Calculate(BASIC, tmp);
	}
	else {
		auto tmp = Go(N / 2);
		return Calculate(tmp, tmp);
	}
}

int M;
int main() {
	cin >> SIZE >> M;
	BASIC.resize(SIZE);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int x;
			cin >> x;
			BASIC[i].push_back(x);
		}
	}
	auto tmp = Go(M);

	for (auto i : tmp) {
		for (auto j : i) {
			cout << j % 1000 << " ";
		}
		cout << endl;
	}












	return 0;
}
