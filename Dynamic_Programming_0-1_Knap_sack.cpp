#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;


int N, K;
//갯수가 중요해지는 문제!
int W[101]; //weight
int G[101]; //worthy
int D[101][1000001]; //무게

int go(int i, int C) {
	if (i == 0 || C == 0) {
		return 0;
	}
	if (W[i] > C) {
		auto result =  go(i - 1, C);
		return D[i][C] = result;
	}
		auto tmp1 = go(i - 1, C);
		auto tmp2 = G[i] + go(i - 1, C - W[i]);
		auto result = max(tmp1, tmp2);
	return D[i][C] = result;
}



int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> G[i];
	}
	cout << go(N, K) << endl;

















	return 0;
}