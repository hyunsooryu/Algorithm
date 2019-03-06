#include "pch.h"
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> Q;
	vector<int> T = { 2,8,19,37,4,5 };
	vector<double> ans;

	double sum = 0.f;
	for (int i = 0; i < T.size(); i++) {
		sum += T[i];
		Q.push(T[i]);
		if (i + 1 < N) {
			ans.push_back(sum / (i + 1));
			continue;
		}
		ans.push_back(sum / N);
		auto tmp = Q.front();
		Q.pop();
		sum -= tmp;
	}

	for (auto j : ans) {
		cout << j << " ";
	}






	return 0;
}