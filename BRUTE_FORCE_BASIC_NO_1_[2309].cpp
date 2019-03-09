#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

//Q. <2309>
//RECURSIVE WAY
bool V[9];
bool no_7() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		if (V[i]) {
			sum += 1;
		}
	}
	return sum == 7;
}
int A[9];
void go(int i, int cnt) {
	if (cnt == 100 || i >= 9) {
		if (cnt == 100 && no_7()) {
			for (int k = 0; k < 9; k++) {
				if (V[k]) {
					cout << A[k] << " ";
				}
			}
			cout << endl;
		}
		return;
	}
	V[i] = true;
	go(i + 1, cnt + A[i]);
	V[i] = false;
	go(i + 1, cnt);
}

//NEXT_PERMUTATION WAY


int main() {
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
	}
	sort(A, A + 9);
	go(0, 0);












	return 0;
}