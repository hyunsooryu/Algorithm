#include <iostream>
using namespace std;

int D[100001][4];



int main() {
	int N;
	cin >> N;
	D[1][1] = 1;
	D[2][2] = 1;
	D[3][1] = 1;
	D[3][2] = 1;
	D[3][3] = 1;
	for (int i = 4; i <= N; i++) {
		D[i][1] = (D[i - 1][2] + D[i - 1][3]) % 1000000009; // 1
		D[i][2] = (D[i - 2][1] + D[i - 2][3]) % 1000000009; // 2
		D[i][3] = (D[i - 3][1] + D[i - 3][2]) % 1000000009; // 3
	}
	cout << (D[N][1] + D[N][2] + D[N][3]) % 1000000009;






	return 0;
}