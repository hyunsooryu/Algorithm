//카드 N개를 사는 방법 중의 최댓 값을 구하여라.
#include <iostream>
using namespace std;
int P[10001];
int D[10001];
int go(int N) {
	cout << N << " ";
	/*if (D[N] > 0) {
		cout << " HIT !! " << N << endl;
		return D[N];
	}*/
	cout << endl;
	if (N == 1) {
		return D[N] = P[1];
	}
	auto tmp = P[N];
	for (int k = 1; k < N; k++) {
		int temp = go(N - k) + P[k];
		if (temp > tmp) {
			tmp = temp;
		}
	}
	return D[N] = tmp;
}


int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	cout << go(N) << endl;
	






	return 0;
}