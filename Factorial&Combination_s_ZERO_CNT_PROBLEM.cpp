#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//How to Solve How many '0' in Factorial? !
/*
5F

5 * 2 * 2 * 3  2 * 1

120  how many set of 5 * 2?

ans = min(cnt(5),cnt(2))
*/

void setTwoAndFive(int N, int& two, int& five) {
	int target = N;
	while (target != 0 && target % 2 == 0) {
		two += 1;
		target = target / 2;
	}
	while (target != 0 && target % 5 == 0) {
		five += 1;
		target = target / 5;
	}
}

int FactorialProblem(int N){
	int _2 = 0;
	int _5 = 0;

	for (int i = 2; i <= N; i++) {
		setTwoAndFive(i, _2, _5);
	}
	return min(_2, _5);
}

int CombinationProblem(int N, int M) {
	int _other = 1;
	auto tmp = M;

	int min_2 = 0;
	int min_5 = 0;
	/*
	
	*/
	int _2 = 0;
	int _5 = 0;
	
	for (int i = 2; i <= M; i++) {
		setTwoAndFive(i, min_2, min_5);
	}
	for (int i = N; i > N - M; i--) {
		setTwoAndFive(i, _2, _5);
	}
	
	_2 = _2 - min_2;
	_5 = _5 - min_5;

	if (_2 <= 0 || _5 <= 0) {
		return 0;
	}
	else {
		return min(_2, _5);
	}


	
}


int main() {
	cout << CombinationProblem(25, 12) << endl;









	return 0;
}