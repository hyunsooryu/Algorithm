#include <iostream>
using namespace std;
int N;
int D[10001];
int T;
int main() {
	cin >> T;
	D[0] = 1;
	for (int k = 1; k <= 3; k++) {
		for (int i = 1; i <= 10001; i++) {
			if (i - k >= 0) {
				D[i] += D[i - k];
			}
		}
	}

	while (T--) {
		int x;
		cin >> x;
		cout << D[x] << endl;
	}
		
	













	return 0;
}