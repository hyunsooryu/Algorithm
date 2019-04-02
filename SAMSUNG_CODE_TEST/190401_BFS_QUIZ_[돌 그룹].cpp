#include <iostream>
#include <queue>
#include <map>
using namespace std;

//크기가 같지 않은 돌 그룹을 2개정한다. A vs B, A vs C, B vc C
//-> 크기가 작은 쪽을 X, 크기가 큰 쪽을 Y라고 정한다. X + X Y - X
//-> 돌의 개수는 음수가 될 수 없다. 
struct BLOCK{
	int A, B, C;
	BLOCK(int A = 0, int B = 0, int C = 0) { this->A = A; this->B = B; this->C = C;}
	bool operator==(const BLOCK& X)const{
		return X.A == A && X.B == B && X.C == C;
	}
	bool isOK() {
		return A == B && B == C && C == A;
	}
};

bool V[500][500][500];

int A, B, C;
int main() {
	cin >> A >> B >> C;
	queue<BLOCK> Q;
	V[A][B][C] = true;
	Q.push(BLOCK(A, B, C));
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		cout << tmp.A << "  " << tmp.B << "  " << tmp.C << endl;
		if (tmp.isOK()) {
			cout << 1 << endl;
			return 0;
		}

		int a = tmp.A;
		int b = tmp.B;
		int c = tmp.C;

		if (a != b) {
			if (a < b) {
				if (!V[a + a][b - a][c]) {
					V[a + a][b - a][c] = true;
					Q.push(BLOCK(a + a, b - a, c));
				}
			}
			else {
				if (!V[a - b][b + b][c]) {
					V[a - b][b + b][c] = true;
					Q.push(BLOCK(a - b, b + b, c));
				}
			}
		}
		if (a != c) {
			if (a < c) {
				if (!V[a + a][b][c - a]) {
					V[a + a][b][c - a] = true;
					Q.push(BLOCK(a + a, b, c - a));
				}
			}
			else {
				if (!V[a - b][b][c + c]) {
					V[a - b][b][c + c] = true;
					Q.push(BLOCK(a - b, b, c + c));
				}
			}

		}
		if (b != c) {
			if (b < c) {
				if (!V[a][b + b][c - b]) {
					V[a][b + b][c - b] = true;
					Q.push(BLOCK(a, b + b, c - b));
				}
			}
			else {
				if (!V[a][b - c][c + c]) {
					V[a][b - c][c + c] = true;
					Q.push(BLOCK(a, b - c, c + c));
				}
			}

		}

	}


	cout << 0 << endl;










	return 0;
}