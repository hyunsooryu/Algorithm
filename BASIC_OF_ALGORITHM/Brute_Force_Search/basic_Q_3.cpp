#include <iostream>
#include <vector>
using namespace std;

//정수 N에 대하여, N을 1, 2, 3의 합으로 나타내는 경우의 수를 알아내시오.
//IMPOSSIBLE , CORRECT , NEED MORE 
//(3^N)
int N;
int cnt = 0;
int go(int sum) {
	if (sum > N) { //IMPOSSIBLE
		return 0;
	}
	if (sum == N) { //CORRECT
		return 1;
	}
	int total = 0;
	for (int i = 1; i <= 3; i++) { //NEED MORE WITH USING(case : 1 or case : 2 or case : 3)
		total += go(sum + i);
	}
	return total;
}

//만약, 중복되지 않아야한다면 어떻게 해야할까요?

//비내림차순을 이용합니다..


int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << go(0) << endl;
	}











	return 0;
}