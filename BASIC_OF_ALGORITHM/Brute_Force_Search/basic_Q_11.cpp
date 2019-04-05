    #include "pch.h"
#include <iostream>
#include <vector>
//N개의 정수로 이루어진 수열이 있을 때, 
//길이가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
//중간에 음수도 있다.

//먹고 안먹고로 충분히 구현할 수 있다.	//2^20
//끝까지 가본 후에 sum값을 구해야만한다. 모두 안먹는건 안된다 대신.
//먹고 안먹기를 시현한다면, 공집합을 포함한 모든 부분집합을 만들어 낼 수 있다는 사실 또한 깨달을 수 있다.
//비트마스크로도 충분히 풀어낼 수 있는문제.

//path는 구해진 수를 보러 일부로 추가

using namespace std;
int A[20];
int target;
int N;
int cnt = 0;
vector<int> path;
void go(int index, int sum, int N) {
	if (index == N) {
		for (auto j : path) {
			cout << j << " ";
		}
		cout << endl;
		if (sum == target) {
			cnt += 1;
		}
		return;
	}
	path.push_back(A[index]);
	go(index + 1, sum + A[index], N);
	path.pop_back();
	go(index + 1, sum, N);
}

int main() {
	cin >> N >> target;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	go(0, 0, N);
	if (target == 0) {
		cnt -= 1; //공집합이 아닌 부분집합이기때문에, 공집합을 제외해줍니다.
	}
	cout << cnt << endl; 









	return 0;
}