#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//total 6 getting from 13 <6 C 13> MAKING SELECTING QUESTION TO PERMUTATION
//IF SELECTING NUMBER IS FIXED, AND THEN YOU CAN USE PERMUTATION AT THIS POINT.
//HOW TO GET A GERMAN'S LOTTERY NOT USING RECURSIVE , BUT USING PERMUTATION WAY.
//CONVERT PERMUTATION to COMBINATION
//(13 C 7) * 13
//(13 C 7) = 1716 * 13 = 22,308
int A[13];
int B[13];
int main() {
	while (true) {
		int x;
		cin >> x;
		if (x == 0) {
			break;
		}
		
		for (int i = 0; i < x; i++) {
			cin >> A[i];
			if (i < 6) {
				B[i] = 0;
			}
			else {
				B[i] = 1;
			}
		}
		//getting
		do {
			for (int i = 0; i < x; i++) {
				if (B[i] == 0) {
					cout << A[i] << " ";
				}
			}
			cout << endl;
		} while (next_permutation(B, B + x));
	}
}