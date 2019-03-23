//https://www.acmicpc.net/problem/15652
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> path;
void go(int index, int cnt, vector<int>& path) {
	if (cnt == M || index > N) {
		if (cnt == M) {
			for (auto j : path) {
				cout << j << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = index; i <= N; i++) {
		path.push_back(i);
		go(i, cnt + 1, path);
		path.pop_back();
	}
}
 

int main() {
	cin >> N >> M;
	go(1, 0, path);










	return 0;
}