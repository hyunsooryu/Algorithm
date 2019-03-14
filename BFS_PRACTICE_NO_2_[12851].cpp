#include <iostream>
#include <queue>

using namespace std;


//BFS
//최소 방법의 수
//X + 1
//X - 1
//X * 2

int V[100001];
int D[100001];
int P[100001];
int S, E;
auto MIN = -1;
int cnt = 0;

void path_finder(int N) {
	if (P[N] == -1) {
		cout << N << " ";
		return;
	}
	path_finder(P[N]);
	cout << N << " ";
	return;
}
void BFS(int N) {
	queue<int> Q;
	V[N] = true;
	D[N] = 0;
	Q.push(N);
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		cout << " ________________________________" << endl;
		cout << D[tmp] << "  " << tmp << endl;
		cout << endl;
		if (tmp == E) {
			if (MIN == -1) {
				MIN = D[tmp];
			}
			if (D[tmp] == MIN) {
				cnt += 1;
			}
		}
		if (D[tmp] > MIN && MIN != -1) {
			break;
		}

		if (tmp + 1 <= 100000 && !V[tmp + 1] && tmp + 1 != E) {
			V[tmp + 1] = true;
			D[tmp + 1] = D[tmp] + 1;
			P[tmp + 1] = tmp;
			Q.push(tmp + 1);
		}

		if (tmp + 1 == E) {
			D[tmp + 1] = D[tmp] + 1;
			P[tmp + 1] = tmp;
			Q.push(tmp + 1);
		}

		if (tmp - 1 >= 0 && !V[tmp - 1] && tmp - 1 != E) {
			V[tmp - 1] = true;
			D[tmp - 1] = D[tmp] + 1;
			P[tmp - 1] = tmp;
			Q.push(tmp - 1);
		}

		if (tmp - 1 == E) {
			D[tmp - 1] = D[tmp] + 1;
			P[tmp - 1] = tmp;
			Q.push(tmp - 1);
		}

		if (tmp * 2 >= 0 && tmp * 2 <= 100000 && !V[tmp * 2] && tmp * 2 != E) {
			V[tmp * 2] = true;
			D[tmp * 2] = D[tmp] + 1;
			P[tmp * 2] = tmp;
			Q.push(tmp * 2);
		}

		if (tmp * 2 == E) {
			D[tmp * 2] = D[tmp] + 1;
			P[tmp * 2] = tmp;
			Q.push(tmp * 2);
		}
	}
}


int main() {
	cin >> S >> E;
	fill(P, P + 100001, -1);
	BFS(S);




	cout << cnt << endl;










	return 0;
}