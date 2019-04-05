#include "pch.h"
#include <iostream>
using namespace std;
//연산자 끼워넣기 IN RECURSIVE WAY
//모든 연산자의 수열을 다 해봐야합니다.
//+ - * /을 모두 이용한 모든 수열을 재귀적으로 구현해냅니다.

int CAL[4];
int A[11];
int C[10];
int MAX = -1000000000;
int MIN = 1000000000;
//N - 1 이상이라면, 경우의 수가 엄청 커집니다.




void go(int index, int sum, int N) {
	if (index == N) {
		if (sum > MAX) {
			MAX = sum;
		}
		if (sum < MIN) {
			MIN = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (CAL[i] > 0) {
			CAL[i]--;
			if (i == 0) {
				go(index + 1, sum + A[index], N);
			}
			else if (i == 1) {
				go(index + 1, sum - A[index], N);
			}
			else if (i == 2) {
				go(index + 1, sum * A[index], N);
			}
			else {
				if (A[index] != 0) {
					go(index + 1, sum / A[index], N);
				}
			}
			CAL[i]++;
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> CAL[i];
	}

	go(1, A[0], N);
	cout << MAX << endl;
	cout << MIN << endl;











	return 0;
}