#include "pch.h"
#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<int, int> D;
int solution(vector<int> food_times, long long k) {
	int answer = 0;
	queue<int> Q;
	int t = 1;
	for (auto j : food_times) {
		D[t] += j;
		t += 1;
	}
	for (int i = 1; i <= food_times.size(); i++) {
		if (D[i] >= 1) {
			Q.push(i);
		}
	}
	int times = 0;
	while (!Q.empty()) {
		cout << times << " ~ " << times + 1 << " : " << Q.front() << endl;
		auto tmp = Q.front();
		Q.pop();
		D[tmp] -= 1;
		if (D[tmp] > 0) {
			Q.push(tmp);
		}
		if (times == k) {
			answer = tmp;
			break;
		}

		times += 1;
	}


	return answer;
}


int main() {
	vector<int> food_times = { 4,3,3 };
	int k = 5;

	cout << solution(food_times, k) << endl;
	









	return 0;
}