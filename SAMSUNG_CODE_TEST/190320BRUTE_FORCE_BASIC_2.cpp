#include <iostream>
using namespace std;
//Tetromino
/*
00000
00000 
00000
00000
00000



*/
int A[501][501];
int N, M;
int MAX = 0;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	/*
	----
	TWICE
	row - 3
	col - 3
	*/
	//row
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M - 3; j++) {
			auto tmp = A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i][j + 3];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}
	//col
	for (int i = 1; i <= N - 3; i++) {
		for (int j = 1; j <= M; j++) {
			auto tmp = A[i][j] + A[i + 1][j] + A[i + 2][j] + A[i + 3][j];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}
	/*
	--
	--
	ONCE
	row - 1
	col - 1
	*/
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j] + A[i + 1][j] + A[i][j + 1] + A[i + 1][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	/*
	-
	-
	--    
	*/
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j] + A[i + 1][j] + A[i + 2][j] + A[i + 2][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j + 1] + A[i + 1][j + 1] + A[i + 2][j + 1] + A[i + 2][j];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i][j] + A[i + 1][j] + A[i + 1][j + 1] + A[i + 1][j + 2];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i + 1][j] + A[i][j] + A[i][j + 1] + A[i][j + 2];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i + 1][j] + A[i + 1][j + 1] + A[i + 1][j + 2] + A[i][j + 2];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i + 1][j + 2];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j] + A[i][j + 1] + A[i + 1][j + 1] + A[i + 2][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j + 1] + A[i][j] + A[i + 1][j] + A[i + 2][j];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i][j + 1] + A[i + 1][j] + A[i + 1][j + 1] + A[i + 1][j + 2];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i + 1][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j] + A[i + 1][j] + A[i + 2][j] + A[i + 1][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j + 1] + A[i + 1][j + 1] + A[i + 2][j + 1] + A[i + 1][j];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j] + A[i + 1][j] + A[i + 1][j + 1] + A[i + 2][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			auto tmp = A[i][j + 1] + A[i + 1][j + 1] + A[i + 1][j] + A[i + 2][j];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i][j + 1] + A[i][j + 2] + A[i + 1][j] + A[i + 1][j + 1];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			auto tmp = A[i][j] + A[i][j + 1] + A[i + 1][j + 1] + A[i + 1][j + 2];
			if (tmp > MAX) {
				MAX = tmp;
			}
		}
	}
	
	cout << MAX << endl;









	return 0;
}