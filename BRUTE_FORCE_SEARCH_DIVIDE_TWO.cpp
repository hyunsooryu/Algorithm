#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> D[4];
int N;
int main() {
	cin >> N;
	
	for (int i = 0; i < 4; i++) {
		D[i].resize(N);
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 4; k++) {
			cin >> D[k][i];
		}
	}

	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A.push_back(D[0][i] + D[1][j]);
			B.push_back(D[2][i] + D[3][j]);
		}
	}

	sort(B.begin(), B.end());
	long long ans = 0;
	for (auto j : A) {
		auto itor = equal_range(B.begin(), B.end(), -j);
		ans += (itor.second - itor.first);
	}

	cout << ans << endl;

	
	




	return 0;
}