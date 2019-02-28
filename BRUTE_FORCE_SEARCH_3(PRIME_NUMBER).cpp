#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
bool normal[4000001];
vector<int> Prime;
int target;
void Erathos(int N) {
	for (int i = 2; i <= N; i++) {
		if (!normal[i]) {
			Prime.push_back(i);
			for (int j = i*2; j <= N; j += i) {
				normal[j] = true;
			}
		}
	}
}

int Solve() {
	int size = Prime.size();
	int S = 0;
	int E = 0;
	int sum = Prime[0];
	int ans = 0;
	while (S <= E && E < size) {
		if (sum == target) {
			for (int k = S; k <= E; k++) {
				cout << Prime[k] << " ";
			}
			cout << endl;
			ans++;
			E += 1;
			if (E < size) {
				sum += Prime[E];
			}
		}
		else if (sum < target) {
			E += 1;
			if (E < size) {
				sum += Prime[E];
			}
		}
		else {
			sum -= Prime[S];
			S += 1;
		}
	}
	return ans;
}

int main() {
	cin >> target;
	Erathos(target);
	cout << Solve() << endl;









	return 0;
}
