#include <iostream>
#include <vector>
using namespace std;

//about LOTTO HOW TO SOLVE IT IN RECURSIVE WAY
//eat or not can be used.


int A[13];
int P[13];

//1way
void go_1(int index, int start, int N) {
	if (index == 6) {
		for (int k = 0; k < 6; k++) {
			cout << A[P[k]] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i < N; i++) {
		P[index] = i;
		go_1(index + 1, i + 1, N);
	}
}
//2way
vector<int> path;
void go_2(int i, int N, int cnt) {
	if (cnt == 6) {
		for (auto j : path) {
			cout << A[j] << " ";
		}
		cout << endl;
		return;
	}
	if (i >= N) {
		return;
	}
	path.push_back(i);
	go_2(i + 1, N, cnt + 1);
	path.pop_back();
	go_2(i + 1, N, cnt);
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	go_1(0, 0, N); //2가지 방법
	go_2(0, N, 0); //2가지 방법 //no 중복 / just N < M 조합문제는 먹고안먹고 전략으로 충분하다.













	return 0;
}
