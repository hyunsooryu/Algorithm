#include "pch.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;
set<string, greater<string>> list;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string name, status;
		cin >> name;
		cin >> status;
		if (status == "enter")
			list.insert(name);
		else
			list.erase(name);
	}

	for (auto j : list) {
		cout << j << endl;
	}

	return 0;
}
