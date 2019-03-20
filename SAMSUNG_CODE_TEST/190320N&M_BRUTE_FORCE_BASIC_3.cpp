#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool V[8];
vector<int> path;
void go(int index, int cnt, vector<int>& path) {
	if (cnt == M) {
		for (auto j : path) {
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	if (index > N) {
		return;
	}
	for (int i = 1; i <= N; i++) {
		path.push_back(i);
		go(i, cnt + 1, path);
		path.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		path.push_back(i);
		go(i, 1, path);
		path.pop_back();
	}

	













	return 0;

}