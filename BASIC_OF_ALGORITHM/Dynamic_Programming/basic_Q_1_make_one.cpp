//1로만들기
#include <iostream>
using namespace std;
int D[1000001];
/*
//D[N] = min(D[N - 1], D[N / 2], D[N / 3]) + 1
*/
//TOP _ BOTTOM
int go(int N) {
	if (N == 1) {
		return 0;
	}
	if (D[N] > 0) {
		return D[N];
	}
	int &tmp = D[N];
	tmp = go(N - 1) + 1;
	if (N % 2 == 0) {
		auto temp = go(N / 2) + 1;
		if (temp < tmp) {
			tmp = temp;
		}
	}
	if (N % 3 == 0) {
		auto temp = go(N / 3) + 1;
		if (temp < tmp) {
			tmp = temp;
		}
	}
	return tmp;
}


//BOTTOM _ UP
int bottom_up(int N) {
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0 && D[i / 2] + 1 < D[i]) {
			D[i] = D[i / 2] + 1;
		}
		if (i % 3 == 0 && D[i / 3] + 1 < D[i]) {
			D[i] = D[i / 3] + 1;
		}
	}
	return D[N];
}

int main() {
	int N;
	cin >> N;
	cout << bottom_up(N) << endl;









	return 0;
}