#include "pch.h"
#include <iostream>
#include <deque>
using namespace std;
int N, wSize;
int A[1001];
int D[1001];

void SlideWindow() {
	deque<pair<int,int>> DEQ;
	for (int i = 0; i < N; i++) {
		
		if (!DEQ.empty()) {
			if (i >= DEQ.front().first + wSize) {
				DEQ.pop_front();
			}
			while (!DEQ.empty()) {
				if (DEQ.front().second >= A[i]) {
					DEQ.pop_front();
				}
				else {
					break;
				}
			}
		}
		DEQ.push_back(make_pair(i, A[i]));
		D[i] = DEQ.front().second;
	}
}

int main() {
	cin >> N >> wSize;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	SlideWindow();

	for (int i = 0; i < N; i++) {
		cout << D[i] << " ";
	}










	return 0;
}