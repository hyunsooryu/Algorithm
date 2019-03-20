#include <iostream>
#include <vector>
using namespace std;

int N;
int A[12];
vector<int> C = { 0,0,0,0 };
int MAX = -1000000000;
int MIN = 1000000000;

void go(int index, int total, vector<int>& C) {
	if (index == N) {	//마지막 숫자까지 계산이 되었을 때,
		if (total > MAX) {
			MAX = total;
		}
		if (total < MIN) {
			MIN = total;
		}
		return;
	}
	if (C[0] > 0) {
		C[0] -= 1;
		go(index + 1, total + A[index + 1], C);
		C[0] += 1;
	}
	if (C[1] > 0) {
		C[1] -= 1;
		go(index + 1, total - A[index + 1], C);
		C[1] += 1;
	}
	if (C[2] > 0) {
		C[2] -= 1;
		go(index + 1, total * A[index + 1], C);
		C[2] += 1;
	}
	if (C[3] > 0) {
		C[3] -= 1;
		go(index + 1, total / A[index + 1], C);
		C[3] += 1;
	}


}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> C[i];
	}
	
	int index = 1;
	int total = A[1];


	if (C[0] > 0) {
		C[0] -= 1;
		go(index + 1, total + A[index + 1], C);
		C[0] += 1;
	}
	if (C[1] > 0) {
		C[1] -= 1;
		go(index + 1, total - A[index + 1], C);
		C[1] += 1;
	}
	if (C[2] > 0) {
		C[2] -= 1;
		go(index + 1, total  * A[index + 1], C);
		C[2] += 1;
	}
	if (C[3] > 0) {
		C[3] -= 1;
		go(index + 1, total / A[index + 1], C);
		C[3] += 1;
	}

	cout << MAX << endl;
	cout << MIN << endl;


















	return 0;
}