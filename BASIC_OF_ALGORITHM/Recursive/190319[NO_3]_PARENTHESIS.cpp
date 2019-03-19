#include <iostream>
#include <string>
using namespace std;

int D[101][101];
string A;

int go(int i, int j) {
	if (D[i][j] >= 0) {
		return D[i][j];
	}
	if (j == i + 1) {
		if (A[i] == '(' && A[j] == ')') {
			return D[i][j] = 1;
		}
		return D[i][j] = 0;
	}
	//1 way
	int flag = 0;
	auto tmp_1 = false;
	auto tmp_2 = false;
	if (A[i] == '(' && A[j] == ')') {
		tmp_1 = go(i + 1, j - 1);
	}
	if (tmp_1 == true) {
		flag = 1;
	}
	//2 way
	int k = 1;
	while (true) {
		if (j - k <= 0) {
			break;
		}
		tmp_2 = go(i, j - k - 1) && go(j - k, j);
		if (tmp_2) {
			flag = 1;
		}
		k += 2;
	}
	return D[i][j] = flag;
}

int main() {
	memset(D, -1, sizeof(D));
	cin >> A;

	if (A.size() & 1) {
		cout << "NO" << endl;
	}
	else {
		if (go(0, A.length() - 1) == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}









	return 0;
}