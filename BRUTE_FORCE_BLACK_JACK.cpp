#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
//BLACK JACK
//CARD NO : 100 ->3장을 뽑아 가장 가까운 수를 만들어야한다.
//2장으로 만들 수 있는 모든 경우의 수: 100 * 100 * 100
set<int> BOX;
int A[101];
int N, M;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cout << endl;
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				BOX.insert(A[i] + A[j] + A[k]);
			}
		}
	}

	auto tmp1 = BOX.lower_bound(M);
	auto tmp2 = BOX.upper_bound(M);
	if (tmp1 == tmp2) {
		if (tmp1 == BOX.end()) {
			cout << *(--tmp1) << endl;
		}
		else if (tmp1 == BOX.begin()) {
			cout << *(tmp1) << endl;
		}
		else {
			tmp1--;
			int dis_1 = abs(M - *tmp1);
			int dis_2 = abs(M - *tmp2);
			cout << *tmp1 << " VS " << *tmp2 << endl;
			if (dis_1 <= dis_2) {
				cout << *tmp1;
			}
			else {
				cout << *tmp2;
			}
		}
	}
	else {
		cout << M << endl;
	}
	cout << "FINISHED" << endl;









	return 0;
}
