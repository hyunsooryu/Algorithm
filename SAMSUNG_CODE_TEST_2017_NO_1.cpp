#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int N;
bool V[21];
int A[21][21];
int ans = -1;
void Calculator(){
	int TEAM_A = 0;
	int TEAM_B = 0;
	vector<int> tmp1 = { 0 };
	vector<int> tmp2 = { 0 };
	for (int i = 1; i <= N; i++) {
		if (V[i]) {
			tmp1.push_back(i);
		}
		else {
			tmp2.push_back(i);
		}
	}
	for (int i = 1; i <= N / 2 - 1; i++) {
		for (int k = i + 1; k <= N / 2; k++) {
			if (A[tmp1[i]][tmp1[k]] > 0) {
				TEAM_A += A[tmp1[i]][tmp1[k]];
			}
			if (A[tmp1[k]][tmp1[i]] > 0) {
				TEAM_A += A[tmp1[k]][tmp1[i]];
			}
			if (A[tmp2[i]][tmp2[k]] > 0) {
				TEAM_B += A[tmp2[i]][tmp2[k]];
			}
			if (A[tmp2[k]][tmp2[i]] > 0) {
				TEAM_B += A[tmp2[k]][tmp2[i]];
			}
		}
	}

	
	if (abs(TEAM_A - TEAM_B) < ans || ans == -1) {
		ans = abs(TEAM_A - TEAM_B);
	}
}

void go(int i, int cnt) {
	if (cnt == (N / 2) || i > N) {
		if (cnt == N / 2) {
			Calculator();
		}
		return;
	}
	V[i] = true;
	go(i + 1, cnt + 1);
	V[i] = false;
	go(i + 1, cnt);
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			A[i][j] = rand() % 10 + 1;
		}
	}

	go(1, 0);
	cout << "_________________" << endl;
	cout << ans << endl;
	cout << "_________________" << endl;





	return 0;
}