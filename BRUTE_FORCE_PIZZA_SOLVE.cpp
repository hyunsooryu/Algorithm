#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int N, M;
int A[1001];
int B[1001];
int S1[1001];
int S2[1001];
int main() {
	cin >> T;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i == 0) {
			S1[i] = A[i];
			continue;
		}
		S1[i] = S1[i - 1] + A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		if (i == 0) {
			S2[i] = B[i];
			continue;
		}
		S2[i] = S2[i - 1] + B[i];
	}
	vector<int> PIZZA2;
	int k = 0;
	while (k < M - 1) {
		for (int i = 0; i < M; i++) {
			int S = i;
			int E = (i + k) % M;
			if (S <= E) {
				cout << S2[E] - S2[S] + B[S] << " ";
				PIZZA2.push_back(S2[E] - S2[S] + B[S]);
			}
			else {
				PIZZA2.push_back(S2[E] - S2[0] + B[0] + S2[M - 1] - S2[S] + B[S]);
				cout << S2[E] - S2[0] + B[0] + S2[M - 1] - S2[S] + B[S] << " ";
			}
		}
		cout << endl;
		k += 1;
	}
	PIZZA2.push_back(S2[M - 1] - S2[0] + B[0]);
	PIZZA2.push_back(0);
	sort(PIZZA2.begin(), PIZZA2.end());

	k = 0;
	long long ans = 0;
	while (k < N - 1) {
		for (int i = 0; i < N; i++) {
			int S = i;
			int E = (i + k) % N;
			if (S <= E) {
				auto itor = equal_range(PIZZA2.begin(), PIZZA2.end(),T - (S1[E] - S1[S] + A[S]));
				ans += (itor.second - itor.first);
				cout << (S1[E] - S1[S] + A[S]) << " ";
			}
			else {
				auto itor = equal_range(PIZZA2.begin(), PIZZA2.end(),T - (S1[E] - S1[0] + A[0] + S1[N - 1] - S1[S] + A[S]));
				ans += (itor.second - itor.first);
				cout << (S1[E] - S1[0] + A[0] + S1[N - 1] - S1[S] + A[S]) << " ";
			}
		}
		cout << endl;
		k += 1;
	}
	auto itor = equal_range(PIZZA2.begin(), PIZZA2.end(), T);
	ans += (itor.second - itor.first);
	itor = equal_range(PIZZA2.begin(), PIZZA2.end(), T - S1[N - 1] + S1[0] + A[0]);
	ans += (itor.second - itor.first);
	cout << ans << endl;
	
	

	
	







	return 0;
}