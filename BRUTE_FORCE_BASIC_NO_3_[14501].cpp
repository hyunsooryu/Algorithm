#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
int A[16]; //	cost days
int P[16]; //	pay
int N;
//BRUTE_FORCE_SEARCH USING RECURSIVE
int go(int day) {
	if (day > N) {
		return 0;
	}
	auto tmp1 = 0;
	auto tmp2 = 0;
	//day 부터
	if (day + A[day] - 1 <= N) {
		tmp1 = go(day + A[day]) + P[day];
	}
	//day 다음날 부터
	if (day + 1 <= N) {
		tmp2 = go(day + 1);
	}
	return max(tmp1, tmp2);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> P[i];
	}

	cout << go(1) << endl;
	












	return 0;
}