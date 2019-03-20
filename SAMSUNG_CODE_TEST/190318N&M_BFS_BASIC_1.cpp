#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool V[10];
void go(int i, int cnt, vector<int>& path) {
	if (cnt == M) {
		for (auto j : path) {
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	for (int j = 1; j <= N; j++) {
		if (V[j]) {
			continue;
		}
		V[j] = true;
		path.push_back(j);
		go(j, cnt + 1, path);
		path.pop_back();
		V[j] = false;
	}	
}




int main() {
	cin >> N >> M;
	vector<int> path;
	for (int i = 1; i <= N; i++) {
		V[i] = true;
		path.push_back(i);
		go(i, 1, path);
		path.pop_back();
		V[i] = false;
	}














	return 0;
}

/*#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool V[10];
int A[10];
void go(int i, int N, int M) {
	if (i == M + 1) {
		for (int k = 1; k <= M; k++) {
			cout << A[k] << " ";
		}
		cout << endl;
		return;
	}
	for (int k = 1; k <= N; k++) {
		if (V[k]) {
			continue;
		}
		V[k] = true;
		A[i] = k;
		go(i + 1, N, M);
		V[k] = false;
	}
}




int main() {
	cin >> N >> M;
	go(1, N, M);












	return 0;
}



*/