#include <iostream>
#include <algorithm>
using namespace std;

//포도주
//0 먹지않음 1 한잔째 2 2잔째
//연속으로 3잔은 먹을 수 없다.
//내가 N번째 음료를 마실 떄.
//*연속 3잔만 아니면 된다.
//D[N][2] = D[N - 1][1]
//D[N][1] = D[N - 1][0]
//내가 N번째 음료를 마시지 않을 때.
//D[N][0] = D[N - 1][0]
//D[N][0] = D[N - 1][1]
//D[N][0] = D[N - 1][2]
//선택이 2가지인 경우에는, 1차원으로도 충분히 응용할 슈 있습니다.

int A[10001];
int D[10001][3];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	//INIT
	D[1][0] = 0;
	D[1][1] = A[1];
	for (int i = 2; i <= N; i++) {
		D[i][0] = max(max(D[i - 1][0], D[i - 1][1]), D[i - 1][2]);
		D[i][1] = D[i - 1][0] + A[i];
		D[i][2] = D[i - 1][1] + A[i];
	}

	cout << max(max(D[N][0], D[N][1]), D[N][2]) << endl;
	 








	return 0;
}