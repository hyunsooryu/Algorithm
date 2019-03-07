#include "pch.h"
#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;


void bubble_Sort(int* A, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 1; j < length - i; j++) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
			}
		}
	}
}
/*
5
0 4
1 2
1 -1
2 2
3 3

____

1 -1
1 2
2 2
3 3
0 4
*/

pair<int, int> A[1001];



int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	[&](pair<int,int>* A, int size)->void{
		sort(A, A + size, [](const pair<int,int>& A, const pair<int,int>& B)->const bool{
			if (A.second < B.second) {
				return true;
			}
			else if (A.second == B.second) {
				if (A.first < B.first) {
					return true;
				}
			}
			return false;
		});
	}(A, N);

	for (auto i = 0; i < N; i++) {
		cout << (A + i)->first << " , " << (A + i)->second << endl;
	}





	return 0;
}