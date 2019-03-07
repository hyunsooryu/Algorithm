#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//MAKE N TO PRIME _ NUMBER ' S MULTIPLE

void go(int N) {
	int t = N;
	vector<int> ans;
	for(int i = 2; i * i <= t; i++) {
		while (N % i == 0) {
			ans.push_back(i);
			N /= i;
		}
	}
	if (N > 1) {
		ans.push_back(N);
	}
		for (auto j : ans) {
			cout << j << " ";
		}
	
}

int main() {
	go(6 * 17);









	return 0;
}