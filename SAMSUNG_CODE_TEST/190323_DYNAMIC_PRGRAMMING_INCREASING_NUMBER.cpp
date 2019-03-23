//https://www.acmicpc.net/problem/11057
#include <iostream>
// %10007
using namespace std;
int D[1001][10];
int N;



int main() {
	cin >> N;
	//when N == 1
	for (int i = 0; i < 10; i++) {
		D[1][i] = 1;
	}

	//when N >= 2
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				D[i][j] += (D[i - 1][k] % 10007);
			}
		}
	}

	//ans
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += D[N][i];
	}
	cout << ans % 10007 << endl;
	

	

















	return 0;
}