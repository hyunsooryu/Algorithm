//https://www.acmicpc.net/problem/10819
#include <iostream>
#include <algorithm>
using namespace std;
int A[8], N;
int MAX = -99999999;
int cal(){
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += abs(A[i] - A[i + 1]);
	}
	return sum;
}
int main() {
	cin >> N;
	int t = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	do {
		int result = cal();
		if (result > MAX) {
			MAX = result;
		}

	} while (next_permutation(A, A + N));
	cout << MAX << endl;
	return 0; 
}