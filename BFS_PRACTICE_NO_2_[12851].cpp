#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;


//BFS
//최소 방법의 수
//X + 1
//X - 1
//X * 2

int V[100001]; //MIN값저장
int D[100001]; //거리저장
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
	V[N] = 0;
	Q.push(N);
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		
		cout << tmp << "   " << V[tmp] << endl;
		if (tmp == E) {
			cnt += 1;
		}
		if (V[tmp] > V[E] && V[E] != -1) {
			break;
		}

		int x = tmp + 1;
		int y = tmp - 1;
		int z = tmp * 2;

		if (x <= 100000) {
			if (V[x] == -1) {
				V[x] = V[tmp] + 1;
				Q.push(x);
			}
			else if (V[tmp] + 1 == V[x]) {
				Q.push(x);
			}
		}

		if (y >= 0) {
			if (V[y] == -1) {
				V[y] = V[tmp] + 1;
				Q.push(y);
			}
			else if (V[tmp] + 1 == V[y]) {
				Q.push(y);
			}
		}

		if (z <= 100000) {
			if (V[z] == -1) {
				V[z] = V[tmp] + 1;
				Q.push(z);
			}
			else if (V[tmp] + 1 == V[z]) {
				Q.push(z);
			}
		}
	}
}


int main(){
	cin >> S >> E;
	fill(V, V + 100001, -1);
	BFS(S);




	cout << cnt << endl;










	return 0;
}