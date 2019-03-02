#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;
vector<int> S1;
vector<int> S2;
int T, N, M;

int main() {
	cin >> T;
	cin >> N;
	A.resize(N);
	S1.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i == 0) {
			S1[i] = A[i];
			continue;
		}
		S1[i] = S1[i - 1] + A[i];
	}
	cin >> M;
	B.resize(M);
	S2.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		if (i == 0) {
			S2[i] = B[i];
			continue;
		}
		S2[i] = S2[i - 1] + B[i];
	}
	
	//targeting _ sort
	vector<int> target;
	int k = 0;
	while (k < M) {
		for (int i = 0; i < M; i++) {
			if (i + k < M) {
				target.push_back(S2[i + k] - S2[i] + B[i]);
			}
		}
		k++;
	}

	sort(target.begin(), target.end());
	long long ans = 0;

	
		k = 0;
	while (k < N) {
		for (int i = 0; i < N; i++) {
			if (i + k < N) {
				auto itor = equal_range(target.begin(), target.end(), T - (S1[i + k] - S1[i] + A[i]));
				ans += itor.second - itor.first;
			}
		}
		k++;
	}
	
	cout << ans << endl;


}