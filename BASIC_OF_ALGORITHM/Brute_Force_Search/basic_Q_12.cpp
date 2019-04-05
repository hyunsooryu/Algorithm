#include "pch.h"
#include <iostream>
using namespace std;
int PERIOD[16];
int MONEY[16];

//RECURSIVE IN 2WAYS.

//먹고 안먹고 -> 모든 조합을 만들어 낼 수 있는 강력한 도구입니다..
//끝을 알아내는 것이 중요합니다.
int N;
int MAX = 0;
//먹든 안먹든 결국 N + 1의 날이 와야합니다.....
void go(int day, int sum) {
	if (day == N + 1) {
		if (sum > MAX) {
			MAX = sum;
		}
		return;
	}
	if (PERIOD[day] + day - 1 <= N) {
		go(day + PERIOD[day], sum + MONEY[day]);
	}
	go(day + 1, sum);
}

//아래와 같은 방법으로도 충분히 풀어낼 수 있습니다.
void go_2(int day, int sum) {
	if (day == N + 1) {
		if (sum > MAX) {
			MAX = sum;
		}
		return;
	}
	for (int i = day; i <= N; i++) {
		if (i + PERIOD[i] - 1 <= N) {
			go(i + PERIOD[i], sum + MONEY[i]);
		}
	}
}

int main() {
	//N + 1일에 무조건 퇴사를 합니다.
	//일은 무조건 N일까지만 할 수 있다는 전제.
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> PERIOD[i] >> MONEY[i];
	}

	go_2(1, 0);

	cout << MAX << endl;







	return 0;
}