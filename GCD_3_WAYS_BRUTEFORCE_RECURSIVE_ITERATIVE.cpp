#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//By_Brute Force way
int GCD_Brute_force(int A, int B) {
	int gcd = 1;
	for (int i = 2; i <= min(A, B); i++) {
		if (A % i == 0 && B % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}



//By_Uclid && Recursive Way
int GCD_R(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD_R(b, a % b);
}

//By_Uclid && Iterative Way
int GCD_I(int A, int B) {
	while (B > 0) {
		int tmp = A;
		A = B;
		B = tmp % B;
	}
	return A;
}

int main() {
	cout << GCD_R(14, 26) << endl;
	cout << GCD_Brute_force(14, 26) << endl;
	cout << GCD_I(64, 128) << endl;
	return 0;
}