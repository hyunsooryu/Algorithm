#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int change_index(char e) {
	if (('a' <= e && e <= 'z') || ('A' <= e && e <= 'Z')) {
		if (isupper(e)) {
			if (e + 13 > 'Z') {
				return 'A' + e + 13 - 'Z' - 1;
			}
			else {
				return e + 13;
			}
		}
		else {
			if (e + 13 > 'z') {
				return 'a' + e + 13 - 'z' - 1;
			}
			else {
				return e + 13;
			}
		}
	}
	return e;
}

int main() {
	string data;
	getline(cin, data);
	cout << data << endl;
	for (auto j : data) {
		cout << char(change_index(j));
	}



	return 0;
}