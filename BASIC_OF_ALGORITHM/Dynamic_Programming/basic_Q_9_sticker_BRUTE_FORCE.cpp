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
int N;
int MAX = 0;
void go(int index, int num, int total) {
	//cout << index << " " << num << " " << total << endl;
	if (index == N) {
		if (total > MAX) {
			MAX = total;
		}
		return;
	}
	if (num == 0) {
		go(index + 1, 1, total + A[1][index]);
		go(index + 1, 2, total);
	}
	else if (num == 1) {
		go(index + 1, 0, total + A[0][index]);
		go(index + 1, 2, total);
	}
	else {
		go(index + 1, 0, total + A[0][index]);
		go(index + 1, 1, total + A[1][index]);
		go(index + 1, 2, total);
	}
	
	
}

int main() {
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}
		go(0, 0, 0);
		go(0, 1, 0);
		go(0, 2, 0);
		cout << MAX << endl;
		MAX = 0;
		//memset(D, 0, sizeof(D));
	}







	
	
	
	
	
	
	
	
	return 0;
}