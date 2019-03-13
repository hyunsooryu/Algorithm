#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//TRAVELING SALES PERSON BY BRUTE_FROCE_ALGORITHM_RECURSIVE
int A[11][11];
int N;
const int INF = 999999999;
bool imPossible[11];

int go(int from, int cnt) {
	cout << from << " " << cnt << endl;
	if (cnt == N) {
		if (A[from][1] == 0) {
			return INF;
		}
		return A[from][1];
	}
	int sum = INF;
	for(int i = 1; i <= N; i++){
		if (!imPossible[i] && A[from][i] > 0) {
			imPossible[i] = true;
			auto tmp = go(i, cnt + 1) + A[from][i];
			if (tmp < sum) {
				sum = tmp;
			}
			imPossible[i] = false;
		}
	}
	return sum;
}

//NEXT_PERMUTATION
int NEXT_PERMUTATION() {
	int ans = INF;
	vector<int> T(N - 1);
	for (int i = 2; i <= N; i++) {
		T[i - 2] = i;
	}
	do {
		int sum = 0;
		if (A[1][T[0]] > 0 && A[T[N - 2]][1] > 0) {
			sum += A[1][T[0]] + A[T[N - 2]][1];
			bool flag = false;
			for (int i = 1; i < N - 1; i++) {
				if (A[T[i - 1]][T[i]] > 0) {
					sum += A[T[i - 1]][T[i]];
				}
				else {
					flag = true;
					break;
				}
			}
			if (!flag) {
				if (sum < ans) {
					ans = sum;
				}
			}
		}
	} while (next_permutation(T.begin(), T.end()));
	return ans;
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	imPossible[1] = true;
	auto result = go(1, 1);
	imPossible[1] = false;
	if (result == INF) {
		cout << 0 << endl;
	}
	else {
		cout << result << endl;
	}

	cout << NEXT_PERMUTATION() << endl;











	return 0;
}