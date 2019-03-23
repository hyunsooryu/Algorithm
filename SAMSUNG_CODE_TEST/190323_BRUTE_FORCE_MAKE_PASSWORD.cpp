//https://www.acmicpc.net/problem/1759
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string target;
string path;
int N, M;
void go(int index, int cnt, string& path) {
	if (cnt == N) {
		int mo = 0;
		int ja = 0;
		for (auto j : path) {
			if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u') {
				mo++;
			}
			else {
				ja++;
			}
		}
		if (mo >= 1 && ja >= 2) {
			cout << path << endl;
		}
		return;
	}
	for (int i = index + 1; i < M; i++) {
		path.push_back(target[i]);
		go(i, cnt + 1, path);
		path.pop_back();
	}
}

int main() {
	cin >> N >> M;
	cin >> target;
	sort(target.begin(), target.end());
	for (int i = 0; i < M; i++) {
		path.push_back(target[i]);
		go(i, 1, path);
		path.pop_back();
	}




	return 0;
}