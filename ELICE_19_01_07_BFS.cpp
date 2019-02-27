#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int _N, _M;
int target;

bool V[10001][10001];
bool possible(int i, int j) {
	return (i >= 0 && j >= 0 && i <= _N && j <= _M);
}

bool BFS() {
	cin >> _N >> _M;
	cin >> target;
	queue<pair<int, int>> Q;
	V[0][0] = true;
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int A = tmp.first;
		int B = tmp.second;
		if (A == target || B == target) {
			return true;
		}
		if (!V[A][0]) {
			V[A][0] = true;
			Q.push(make_pair(A, 0));
		}
		if (!V[0][B]) {
			V[0][B] = true;
			Q.push(make_pair(0, B));
		}

		if (!V[_N][B]) {
			V[_N][B] = true;
			Q.push(make_pair(_N, B));
		}
		if (!V[A][_M]) {
			V[A][_M] = true;
			Q.push(make_pair(A, _M));
		}

		//A를 주기
		if (A >= _M - B) {
			if (!V[A - (_M - B)][_M] && possible(A - (_M - B),_M)) {
				V[A - (_M - B)][_M] = true;
				Q.push(make_pair(A - (_M - B), _M));
			}
		}
		else {
			if (!V[0][B + A]) {
				V[0][B + A] = true;
				Q.push(make_pair(0, A + B));
			}
		}

		if (B >= _N - A) {
			if (!V[_N][B - (_N - A)] && possible(_N, B - (_N - A))) {
				V[_N][B - (_N - A)] = true;
				Q.push(make_pair(_N, B - (_N - A)));
			}
		}
		else {
			if (!V[B + A][0]) {
				V[B + A][0] = true;
				Q.push(make_pair(A + B, 0));
			}
		}


	}
	return false;
}

int main() {


	if (BFS()) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}













	return 0;
}
