//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A[13];
//GERMAN LOTTO 2 - WAYS
//6개를 뽑아야하는데 0 1 2 3 4 5 6  N = 7
//RECURSIVE
void go(int index, int cnt, vector<int>& path, int N) {
	if (cnt == 6) {
		for (auto j : path) {
			cout << A[j] << " ";
		}
		cout << endl;
	}
	if (index == N) {
		cout << " ㅠㅠ " << endl;
		return;
	}
	for (int i = index + 1; i < N; i++) {
		if (cnt + N - i < 6) { //될성부를 떡잎만 RECURSIVE를 부르는 CONTOLLER 재귀의 양을 줄여준다.
			continue;
		}
		path.push_back(i);
		go(i, cnt + 1, path, N);
		path.pop_back();
	}
}

//NEXT_PERMUTATION
void Next_Permutation(vector<int>& B){
	int size = B.size();
	do {
		for (int i = 0; i < size; i++) {
			if (B[i] == 0) {
				cout << A[i] << " ";
			}
		}
		cout << endl;
	} while (next_permutation(B.begin(), B.end()));
}
int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		vector<int> B(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A, A + N);
		for (int i = 0; i < 6; i++) {
			B[i] = 0;
		}
		for (int i = 0; i < N - 6; i++) {
			B[i + 6] = 1;
		}
		/*
		vector<int> path;
		for (int i = 0; i < N; i++) {
			if (N - i < 6) {
				continue;
			}
			path.push_back(i);
			go(i, 1, path, N);
			path.pop_back();
		}
		*/
		Next_Permutation(B);

	}







	return 0;
}