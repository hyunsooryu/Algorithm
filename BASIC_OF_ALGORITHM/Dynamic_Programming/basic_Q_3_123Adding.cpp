#include <iostream>
using namespace std;
//1,2,3 adding
int D[1000001];
int go(int N) {
	if (D[N] > 0) {
		return D[N];
	}
	if (N == 0) {
		return D[N] = 1;
	}
	int& tmp = D[N];
	tmp += go(N - 1);
	if (N - 2 >= 0) {
		tmp += go(N - 2);
	}
	if (N - 3 >= 0) {
		tmp += go(N - 3);
	}
	return tmp;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << go(N) << endl;
	}






	return 0;
}