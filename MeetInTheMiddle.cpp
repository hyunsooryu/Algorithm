#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;
vector<int> path;

int go(int N, int I) {
	if (N == M || I >= A.size()) {
		if (N == M) {
			for (auto j : path) {
				cout << j << " ";
			}
			cout << endl;
			return 1;
		}
			return 0;
		}
	auto total = 0;
	path.push_back(A[I]);
	total += go(N + A[I], I + 1);
	path.pop_back();
	total += go(N, I + 1);
	return total;
}

int MeetInTheMiddle() {

	int mid = (0 + N - 1) / 2;
	vector<int> temp1;
	vector<int> temp2;

	temp1.assign(A.begin(), A.begin() + mid + 1);
	temp2.assign(A.begin() + mid + 1, A.end());

	int temp1_size = mid + 1;
	int temp2_size = N - temp1_size;
	vector<int> tmp1;
	vector<int> tmp2;
	for (int i = 0; i < (1 << temp1_size); i++) {
		int ans = 0;
		for (int j = 0; j < temp1_size; j++) {
			if (i & (1 << j)) {
				ans += temp1[j];
			}
		}
		tmp1.push_back(ans);
	}

	for (int i = 0; i < (1 << temp2_size); i++) {
		int ans = 0;
		for (int j = 0; j < temp2_size; j++) {
			if (i & (1 << j)) {
				ans += temp2[j];
			}
		}
		tmp2.push_back(ans);
	}
	sort(tmp1.begin(), tmp1.end());
	sort(tmp2.begin(), tmp2.end());
	int ans = 0;
	for (auto j : tmp1) {
		auto target = M - j;
		auto itor = equal_range(tmp2.begin(), tmp2.end(), target);
		ans += (itor.second - itor.first);

	}
	if (M == 0) {
		ans -= 1;
	}
	return ans;

}

int main(){
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		A[i] = i + rand() % 11 + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << MeetInTheMiddle() << endl;

	cout << go(0, 0) << endl;





	return 0;
}
