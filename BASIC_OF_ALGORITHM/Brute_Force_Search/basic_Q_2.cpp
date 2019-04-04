#include <iostream>
using namespace std;
//준규가 사는 나라는 E, S, M이라는 연도를 사용합니다. 
int A[3];
int E, S, M;
int year = 1;

int main() {
	cin >> E >> S >> M;
	int e = 1;
	int s = 1;
	int m = 1;
	int year = 1;
	while(true){
		if (e == E && s == S && m == M) {
			cout << year << endl;
			break;
		}
		if (e == 15 && s == 28 && m == 19) {
			cout << -1 << endl;
			break;
		}

		e += 1;
		s += 1;
		m += 1;

		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
		year += 1;
	}



	return 0;
}