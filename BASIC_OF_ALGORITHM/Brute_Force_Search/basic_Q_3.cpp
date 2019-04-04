#include <iostream>

using namespace std;

//정수 N에 대하여, N을 1, 2, 3의 합으로 나타내는 경우의 수를 알아내시오.
int N;
int cnt = 0;
int go(int sum) {
	if (sum > N) {
		return 0;
	}
	if (sum == N) {
		return 1;
	}
	int total = 0;
	for (int i = 1; i <= 3; i++) {
		total += go(sum + i);
	}
	return total;
}

//만약, 중복되지 않아야한다면 어떻게 해야할까요?

//비내림차순을 이용합니다..

int go_2(int sum, vector<int> A){

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << go(0) << endl;
	}











	return 0;
}