/*
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[64];
int t = 0;
vector<vector<int>> PATH;
void go(int i, int cnt, vector<int> path) {
	if (cnt == 3) {
		t += 1;
		PATH.push_back(path);
		return;
	}
	for (int k = i + 1; k < 64; k++) {
		path.push_back(A[k]);
		go(k, cnt + 1, path);
		path.pop_back();
	}
}
int main() {
	int k = 1;
	for (auto& j : A) {
		j += k++;
	}
	vector<int> path;
	for (int k = 0; k < 64; k++) {
		path.push_back(A[k]);
		go(k + 1, 1, path);
		path.pop_back();
	}

	cout << t / 3 << endl;

	return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
vector<int> B;
int main() {
	for (int i = 0; i < 3; i++) {
		B.push_back(0);
	}
	for (int i = 0; i < 61; i++) {
		B.push_back(1);
	}

	for (int i = 0; i < 64; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 64; i++) {
		A.push_back(i + 1);
	}
	int t = 0;
	do {
		for (int i = 0; i < 64; i++) {
			if (B[i] == 0) {
				t++;
			}
		}
	} while (next_permutation(B.begin(), B.end()));

	cout << t / 3 / 3 << endl;





	return 0;
}