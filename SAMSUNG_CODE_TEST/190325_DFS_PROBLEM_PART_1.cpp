#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int A[10];

bool Solve(int target) {
	vector<int> B;
	for (int i = 0; i < 2; i++) {
		B.push_back(0);
	}
	for (int i = 0; i < N - 2; i++) {
		B.push_back(1);
	}
	do {
		vector<int> temp;
		for (int i = 0; i < N; i++) {
			if (B[i] == 0) {
				temp.push_back(A[i]);
			}
		}
		cout << "비교시작 : " << temp[0] << " 과 " << temp[1] << " 을 비교합니다." << endl;
		cout << "만들 수 있는 각도(차) : " << abs(temp[0] - temp[1]) << " " << endl;
		cout << "만들 수 있는 각도(합) : " << temp[0] + temp[1] << " " << endl;
		
		if (abs(temp[0] - temp[1]) == target || (temp[0] + temp[1]) == target) {
			return true;
		}
		
	} while (next_permutation(B.begin(), B.end()));
	return false;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	
	while (K--) {
		int target;
		cin >> target;
		if (Solve(target)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	












	return 0;
}