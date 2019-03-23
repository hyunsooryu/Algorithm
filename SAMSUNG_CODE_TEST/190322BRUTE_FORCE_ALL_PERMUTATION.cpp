//https://www.acmicpc.net/problem/10974
#include <iostream>
#include <algorithm>

using namespace std;

int A[8];
int main() {
	int N;
	cin >> N;
	int t = 1;
	for_each(A, A + N, [&](int& nVal) {
		nVal = t++;
	});
	do {
		for_each(A, A + N, [](int nVal) {
			printf_s("%d ", nVal);
		});
		printf_s("\n");
	} while (next_permutation(A, A + N));

	return 0; 
}