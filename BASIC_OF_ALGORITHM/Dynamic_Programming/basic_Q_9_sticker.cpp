#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int A[2][100001];
int D[3][100001];
/*
나의 상황
//내가 아무것도 고르지 않는다면, 앞이 뭐든 다 올수있다.

//내가 위쪽을 고른다면, 앞에서 아래쪽이온다.

//내가 아래쪽을 고른다면, 앞에서는 위쪽이온다.
3가지 상황
*/
int main() {
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}
		D[0][0] = A[0][0]; //윗
		D[1][0] = A[1][0]; //아래
		D[2][0] = 0; //둘다 안먹
		for (int j = 1; j < N; j++) {
			D[0][j] = max(D[1][j - 1],D[2][j - 1]) + A[0][j];
			D[1][j] = max(D[0][j - 1],D[2][j - 1]) + A[1][j]; 
			D[2][j] = max(max(D[0][j - 1], D[1][j - 1]), D[2][j - 1]);
		}
		cout << max(max(D[0][N - 1], D[1][N - 1]), D[2][N - 1]) << endl;
		memset(D, 0, sizeof(D));
	}







	
	
	
	
	
	
	
	
	return 0;
}