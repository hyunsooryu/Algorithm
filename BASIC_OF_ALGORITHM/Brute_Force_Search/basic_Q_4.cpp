#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//순서가 다르고, 1 ~ N까지 한번씩 등장할 수 있는 모든 경우의 수 = permutation
bool Next_Permutation(vector<int>& A) {
	int SIZE = A.size();
	int i = SIZE - 1;
	int j = SIZE - 1;
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
	for (; j >= i; j--) {
		if (A[i - 1] < A[j]) {
			swap(A[i - 1], A[j]);
			break;
		}
	}
	reverse(A.begin() + i, A.end());
	return true;
}

int main() {
	




	return 0;
}