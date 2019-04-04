#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

//비내림차순
//Combination N C M 중복금지
int A[10];
int cnt[10];
int T[10];
int V[10];

void go(int index, int start, int N, int M) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = start; i < N; i++) {
		//cnt[i] -= 1;
		A[index] = T[i];
		go(index + 1, i, N, M);
		//cnt[i] += 1;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	sort(V, V + N);
	T[0] = V[0];
	cnt[0] = 1;
	int k = 0;
	for (int i = 1; i < N; i++) {
		if (V[i - 1] == V[i]) {
			cnt[k] += 1;
		}
		else {
			k += 1;
			cnt[k] = 1;
			T[k] = V[i];
		}

	}
	/*
	for (int i = 0; i <= k; i++) {
		cout << T[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= k; i++) {
		cout << cnt[i] << " ";
	}
	*/
	cout << endl;
	cout << endl;

	go(0, 0, k + 1, M);













	return 0;
}