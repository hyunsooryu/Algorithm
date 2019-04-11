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

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> LIST = {4,3,3};
int Size = 0;
map<int, vector<int>> D;
map<int, bool> V;
map<int, bool> NO;
int main() {
	Size = LIST.size();
	int top = 0;
	int target = 5 - 1;
	for (int i = 0; i < LIST.size(); i++) {
		D[LIST[i]].push_back(i);
	}
	sort(LIST.begin(), LIST.end());
	while (true) {
		if (V[LIST[top]]) {
			top += 1;
			continue;
		}
		cout << "TARGET : " << target << endl;
		if (!V[LIST[top]]) {
			V[LIST[top]] = true;
		}
		cout << "TOP : " << LIST[top] << endl;
		cout << "LIST[top] * Size : " << LIST[top] * Size << endl;
		if (target >= LIST[top] * Size) {
			target %= LIST[top] * Size;
			for (auto j : D[LIST[top]]) {
				NO[j] = true;
				Size -= 1;
			}
			top += 1;
		}
		else {
			target %= Size;
			cout << target << endl;

			for (int k = 0; k < LIST.size(); k++) {
				if (!NO[k]) {
					cout << k << " ";
				}
			}
			cout << endl;
			break;
		}
	}












	return 0;
}



*/
