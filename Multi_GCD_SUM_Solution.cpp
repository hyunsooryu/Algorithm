#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//최대 공약수
int GCD(int A, int B) {
	if (B == 0) {
		return A;
	}
	return GCD(B, A % B);
}
//최소 공배수
int LCM(int A, int B) {
	if (A == B) {
		return  A;
	}
	int a = A;
	int b = B;
	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return A * B / a;
}

/*
Possibility of All Pairs of GCD Problem Solving 

IF Not Using Euclid at Here, N time Limited can not be satisfied
A B C D
 x

 A-B
 A-C
 A-D
 B-C
 B-D
 C-D

 4 * 3
 / 2
*/

bool Next_permutation(vector<int>& A) {
	int size = A.size();
	int i = size - 1;
	int j = size - 1;
	bool flag = false;
	for (; i > 0; i--) {
		if (A[i - 1] < A[i]) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		return false;
	}
	for (; i <= j; j--) {
		if (A[i - 1] < A[j]) {
			iter_swap(A.begin() + (i - 1), A.begin() + j);
			break;
		}
	}
	reverse(A.begin() + i, A.end());
	return true;
}


int Combination_with_Next_Permutation(vector<int>& A) {
	int sum = 0;
	int size = A.size();
	vector<int> tmp(size);
	for (int i = 0; i < 2; i++) {
		tmp[i] = 0;
	}
	for (int i = 2; i < size; i++) {
		tmp[i] = 1;
	}
	do {
		int target_1 = -1;
		int target_2 = -1;
		for (int i = 0; i < size; i++) {
			if (tmp[i] == 0) {
				if (target_1 < 0) {
					target_1 = A[i];
				}
				else {
					target_2 = A[i];
				}
			}
		}
		sum += GCD(target_1, target_2);
	} while (Next_permutation(tmp));
	return sum;
}

int Combination_with_Brute_Force_Iterative_way(vector<int>& A){
	int size = A.size();
	int sum = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			sum += GCD(A[i], A[j]);
		}
	}
	return sum;
}
vector<int> path;
int Combination_with_Recursive_Searching_way(vector<int> A, int i, int cnt) {
	if (i >= A.size() || cnt == 2) {
		if (cnt == 2) {
			return GCD(A[path[0]], A[path[1]]);
		}
		return 0;
	}
	auto sum = 0;
	path.push_back(i);
	sum += Combination_with_Recursive_Searching_way(A, i + 1, cnt + 1);
	path.pop_back();
	sum += Combination_with_Recursive_Searching_way(A, i + 1, cnt);
	return sum;
}



int main() {
	vector<int> A(100);
	
	for (int i = 0; i < 100; i++) {
		A[i] = 1 + i;
	}

	cout << Combination_with_Next_Permutation(A) << endl;
	cout << Combination_with_Brute_Force_Iterative_way(A) << endl;
	cout << Combination_with_Recursive_Searching_way(A, 0, 0) << endl;

}