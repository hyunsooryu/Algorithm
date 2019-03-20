#include <iostream>
#include <vector>
using namespace std;
bool V[9];
vector<int> A;
int N, M;
void go(int i, int cnt) {
	if(cnt == M){
		for (auto j : A) {
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	for (int j = i + 1; j <= N; j++) {
		if (!V[j]) {
			V[j] = true;
			A.push_back(j);
			go(j, cnt + 1);
			A.pop_back();
			V[j] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= (N - M) + 1; i++) {
		V[i] = true;
		A.push_back(i);
		go(i, 1);
		A.pop_back();
		V[i] = false;
	}













	return 0;
}