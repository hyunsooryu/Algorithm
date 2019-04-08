#include <iostream>
using namespace std;
//1,2 ,3 더하기입니다.하지만 같은 수가 연속해서 2번와서는 안된다.
//초기값
/*D[N][K] = ? N의값이고, 마지막에 더한수가 K인 갯수.
D[N][1] = D[N - 1][2] + D[N - 1][3] 
D[N][2] = D[N - 2][1] + D[N - 2][3] 
D[N][3]	= D[N - 3][1] + D[N - 3][2]

ans = SUM(D[N][K])(1 <= K <= 3)
*/
int D[1000001][4];
int bottom_up(int N) {
	D[1][1] = 1;
	D[2][2] = 1;
	D[3][1] = 1;
	D[3][2] = 1;
	D[3][3] = 1;
	for (int i = 4; i <= N; i++) {
		D[i][1] = D[i - 1][2] + D[i - 1][3] % 1000000009;
		D[i][2] = D[i - 2][1] + D[i - 2][3] % 1000000009;
		D[i][3] = D[i - 3][1] + D[i - 3][2] % 1000000009;
	}
	return (D[N][1] + D[N][2] + D[N][3]) % 1000000009;
}


int main(){
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << bottom_up(N) << endl;
	}
	












	return 0;
}