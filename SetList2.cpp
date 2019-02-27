#include "pch.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;


set<string> list;
set<string> ans;
int main() {
	int N, M;
	cin >> N >> M;
	int T = N + M;
	int cnt = 0;
	string name;
	while (T--) {
		cin >> name;
		if (list.find(name) == list.end()) {
			list.insert(name);
			continue;
		}
		++cnt;
		ans.insert(name);
	}

	cout << cnt << endl;
	for (string i : ans) {
		cout << i << endl;
	}












	return 0;
}
