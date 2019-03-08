#include "pch.h"
#include <iostream>
using namespace std;

//HOW TO FIND A CYCLE 
int A, P;
int V[10001];
int Calculate(int N) {
	int tmp = N;
	int total = 0;
	while (tmp != 0){
		int target = tmp % 10;
		int sum = 1;
		for (int i = 0; i < P; i++) {
			sum *= target;
		}
		total += sum;
		tmp /= 10;
	}
	return total;
}

int DFS(int N, int order) {
	cout << N << " ";
	if (V[N] > 0) {
		return V[N] - 1;
	}
	V[N] = order;
	return DFS(Calculate(N),order + 1);
}

int main() {
	cin >> A >> P;
	cout << DFS(A, 1) << endl;

	return 0;
}