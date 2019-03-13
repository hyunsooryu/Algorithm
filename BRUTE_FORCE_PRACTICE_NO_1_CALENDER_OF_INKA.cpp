
#include <iostream>
using namespace std;

int go(int i, int j, int N, int M){
	if (N == M) {
		return j;
	}
	if (N > M) {
		swap(N, M);
		swap(i, j);
	}
	int t = N;
	int point = int(abs(N - M));
		int diff = i - j;
		int A = 0;
		int B = -N;
		int year = 0;
		int n = 0;
		while (A != diff && B != diff) {
			A += point;
			B += point;
			year += M;
			if (n > 0 && (int(abs(A)) == t || int(abs(B)) == t)) {
				return -1;
			}
			n += 1;
		}
		return year + j;
}

int T;
int main() {
	cin >> T;
	while (T--) {
		int N, M, x, y;
		cin >> N >> M >> x >> y;
		cout << go(x, y, N , M) << endl;
	}






	return 0;
}
