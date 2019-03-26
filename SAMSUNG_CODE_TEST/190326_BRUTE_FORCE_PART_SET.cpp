#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//BRUTE_FORCE
bool V[20];
int A[20];
int N, K;
int go(int index, int sum, int target) {
	if (sum == target) {
		return 1;
	}
	if (sum > target || index >= N) {
		return 0;
	}
	V[index] = true;
	go(index + 1, sum + A[index], target);
	V[index] = false;
	go(index + 1, sum, target);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	auto result = go(0, 0, K);
	cout << result << endl;







	return 0;
}