#include <iostream>
#include <algorithm>
using namespace std;
int A[8], N;
int MAX = -200000000;
//10F
//FACTORIAL? 10! less can do i t EVERY F = N * N!
//MAX 8! = 40320 
//FIXED 8 for each permutation
//8 ! * 8 = 322560 !!!
//sorting_time = N * log N
//(8! * 8) + (8 * 3)
void cal(int* A) {
	int total = 0;
	for (int i = 1; i < N; i++) {
		total += abs(A[i - 1] - A[i]);
	}
	if (MAX < total) {
		MAX = total;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N); //정렬을 해줬다.
	do {
		cal(A);
	} while (next_permutation(A, A + N));


	cout << MAX << endl;



	return 0;
}