#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[11]; //num of num == 11 but the thing that we have to use isnt num, its moss.
//num's order would not changed. //only changed in moss. this is the point, when we can use permutation.///
int CAL[4];
vector<int> B;
int MAX = -1000000000;
int MIN = 1000000000;
int main() {
	int N;
	cin >> N;
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
		int total = A[0];
		for (int i = 1; i < N; i++) {
			if (B[i - 1] == 0) {
				total += A[i];
			}
			else if (B[i - 1] == 1) {
				total -= A[i];
			}
			else if (B[i - 1] == 2) {
				total *= A[i];
			}
			else {
				total /= A[i];
			}
		}
		if (total > MAX) {
			MAX = total;
		}
		if (total < MIN) {
			MIN = total;
		}
	} while (next_permutation(B.begin(), B.end()));

	cout << MAX << endl;
	cout << MIN << endl;













	return 0;
}