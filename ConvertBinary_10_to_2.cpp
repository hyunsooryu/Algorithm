#include "pch.h"
#include <iostream>
#include <string>
using namespace std;



/*
9 =	1001

*/
string go(int N) {
	if (N == 0) {
		return "";
	}
	string tmp = "";
	if (N & 1) { //odd
		tmp = go(N / 2);
		tmp.push_back('1');
	}
	else { //even
		tmp = go(N / 2);
		tmp.push_back('0');

	}
	return tmp;
}

int main() {
	int N;
	cin >> N;
	cout << go(N) << endl;









	return 0;
}
