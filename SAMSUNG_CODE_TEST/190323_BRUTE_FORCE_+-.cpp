//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int A[11];
int C[4];
int MIN = 1000000000;
int MAX = -1000000000;
int main() {
	int N;
	cin >> N;
	vector<int> B;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		while (x--) {
			B.push_back(i);
		}
	}
	do {
		int sum = A[0];
		for (int i = 0; i < N - 1; i++) {
			if (B[i] == 0) {
				sum += A[i + 1];
			}
			else if (B[i] == 1) {
				sum -= A[i + 1];
			}
			else if (B[i] == 2) {
				sum *= A[i + 1];
			}
			else{
				sum /= A[i + 1];
			}
		}
		if (sum > MAX) {
			MAX = sum;
		}
		if (sum < MIN) {
			MIN = sum;
		}
	} while (next_permutation(B.begin(), B.end()));

	cout << MAX << endl;
	cout << MIN << endl;

	return 0;
}