#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int D[10001];
bool C[10001];

pair<int, int> candy[10001];

int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> candy[i].first;
		cin >> candy[i].second;

	}
	D[0] = 0;
	for (int i = 1; i <= m; i++) {
		D[i] = 0;
		for (int j = 0; j < n; j++) {
			if (candy[j].second <= i && D[i - candy[j].second] + candy[j].first > D[i]) {
				D[i] = D[i - candy[j].second] + candy[j].first;
			}
		}
	}

	cout << *max_element(D + 1, D + m + 1) << endl;



	return 0;
}
