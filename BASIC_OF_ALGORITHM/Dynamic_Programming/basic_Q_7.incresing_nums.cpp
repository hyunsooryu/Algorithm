#include <iostream>
#include <numeric>
using namespace std;

int D[101][10];
//
//D[N][K] = SUM(D[N - 1][J](0<=J<=K))
int bottom_up(int N) {
	//INIT
	for (int j = 0; j < 10; j++) {
		D[1][j] = 1;
	}

	//SOLVING
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				D[i][j] += (D[i - 1][k] % 10007);
			}
		}
	}
	int ans = 0;
	ans = accumulate(D[N], D[N] + 10, 0);
	return ans % 10007;
}

int main() {
	int N;
	cin >> N;
	cout << bottom_up(N) << endl;











	return 0;
}