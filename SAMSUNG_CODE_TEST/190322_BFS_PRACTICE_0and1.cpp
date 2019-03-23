#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

bool BFS(int);
bool Calculate(unsigned long long, int);
int N;

int main() {
	cin >> N;
	if(!BFS(N)) {
		cout << "BRAK" << endl;
	}
	return 0;
}
bool Calculate(unsigned long long A, int tmp) {
	if (A % tmp == 0) {
		return true;
	}
	return false;
}

bool BFS(int N) {
	queue<unsigned long long> Q;
	Q.push(1);
	while (!Q.empty()) {
		auto top = Q.front();
		Q.pop();
		if (Calculate(top, N)) {
			cout << top << endl;
			return true;
		}

		auto target_zero = top * 10;
		if (target_zero > top) {
			Q.push(target_zero);
		}
		auto target_one = top * 10 + 1;
		if (target_one > top) {
			Q.push(target_one);
		}
	}
	return false;
}