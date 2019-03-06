#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main() {
	string target;
	set<string> SET;
	cin >> target;
	int last_index = target.length() - 1;
	int size = last_index + 1;
	for (int i = 0; i <= last_index; i++) {
		SET.insert(target.substr(i, size--));
	}

	for (auto j : SET) {
		cout << j << endl;
	}
	




	return 0;
}