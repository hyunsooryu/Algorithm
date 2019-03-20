#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int A[10001];
int D[10001][3];
int MAX[10001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	D[1][0] = 0;
	D[1][1] = 6;
	D[1][2] = 0;
	for (int i = 2; i <= N; i++) {
		D[i][0] = max(max(D[i - 1][0], D[i - 1][1]), D[i - 1][2]);
		D[i][1] = D[i - 1][0] + A[i];
		D[i][2] = D[i - 1][1] + A[i];
		MAX[i] = max(max(D[i][0], D[i][1]), D[i][2]);
	}

	cout << MAX[N] << endl;

	












	return 0;
}

/*
#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int A[10001];
int D[10001];
int MAX = -1;
int main(){
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	D[1] = A[1];
	D[2] = D[1] + A[2];
	MAX = D[2];
	for (int i = 3; i <= N; i++) {
		//마시지 않을때
		int tmp = D[i - 1];
		//첫잔일 때
		if (D[i - 2] + A[i] > tmp) {
			tmp = D[i - 2] + A[i];
		}
		//두번째잔일 때
		if (D[i - 3] + A[i - 1] + A[i] > tmp) {
			tmp = D[i - 3] + A[i - 1] + A[i];
		}
		D[i] = tmp;
		if (D[i] > MAX) {
			MAX = D[i];
		}
	}

	
	cout << MAX << endl;







	return 0;
}


*/