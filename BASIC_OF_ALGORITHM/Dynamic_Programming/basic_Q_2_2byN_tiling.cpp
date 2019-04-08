#include <iostream>
using namespace std;
//2*N _ BY TILING
int D[100001];
//TOP_DOWN{
int go(int N) {
	if (D[N] > 0) {
		cout << "HIT! -> " << N << endl;
		return D[N];
	}
	if (N == 0) {
		return 1;
	}
	int& tmp = D[N];
	//call the small problems + my_problem(but no right_now)
	tmp += go(N - 1) % 10007;
	if (N - 2 >= 0) { //call the small problems + my_problem(but no right_now)
		tmp += go(N - 2) % 10007;
	}
	return tmp;
}
//

//BOTTOM_UP{
int bottom_up(int N) {
	D[0] = 1;
	D[1] = 1;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 2];
		D[i] %= 10007;
	}
	return D[N];
}

//}
int main() {
	int N;
	cin >> N;
	cout << bottom_up(N) << endl;










	return 0;
}