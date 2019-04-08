#include <iostream>
#include <algorithm>
using namespace std;
//쉬운계단수..인접한 자리의 수가 1차이가 나는 수를 고르라.
/*
D[N][0] = D[N - 1][1]
D[N][1] = D[N - 1][0] + D[N - 1][2]
D[N][2] = D[N - 1][1] + D[N - 1][3]
D[N][3] = D[N - 1][2] + D[N - 2][4]
			  ...
			  ...
D[N][8] = D[N - 1][7] + D[N - 1][9]
D[N][9] = D[N - 1][8] 

ans = SUM(D[N][K])(0 <= K <= 9)
*/
long long D[101][10];
int main() {
	int N;
	cin >> N;
	for (int j = 1; j < 10; j++) {
		D[1][j] = 1;
	}
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][1] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % 1000000000;
		}
		D[i][9] = D[i - 1][8] % 1000000000;
	}
	long long ans = 0;
	for_each(D[N], D[N] + 10, [&](int K)->void{
		ans += K;
	});

	cout << ans % 1000000000 << endl;












	return 0;
}