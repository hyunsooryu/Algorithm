#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string input;
	string A, B, C, D;
	cin >> A >> B >> C >> D;
	A = A + B;
	C = C + D;
	
	cout << stoll(A) + stoll(C) << endl;







	return 0;
}