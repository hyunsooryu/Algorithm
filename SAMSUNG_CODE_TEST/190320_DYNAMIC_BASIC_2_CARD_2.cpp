#include <iostream>

using namespace std;
int P[10001];
int D[10001];
bool V[10001];

int go(int N) {
	if (V[N]) {
		cout << "HIT" << endl;
		return D[N];
	}
	auto MIN = P[N];
	for (int i = 1; i < N; i++) {
		auto temp = go(N - i) + P[i];
		if (temp < MIN) {
			MIN = temp;
		}
	}
	V[N] = true;
	return D[N] = MIN;
}


int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	cout << go(N) << endl;













	return 0;
}