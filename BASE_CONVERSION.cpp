#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
//HOW TO MAKE CONVERSION BETWEEN STRING TYPE AND INT TYPE

//string - > int 
int stringToInt(const string& e) {
	return stoi(e);
}
//int -> string
string intToString(const int e) {
	return to_string(e);
}

//HOW TO MAKE CONVERSION BETWEEN NO-TYPE BASE 
//TEN to N
string tenToN(int e, int N) {
	string ans = "";
	while (e > 0) {
		ans.push_back(e % N + '0');
		e = e / N;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return ans;
}
//N to Ten

/*
 0101

 8 * A + 4 * B + 2 * C + 1 * D
 
 2(4 * A + 2 * B + 1 * C) + 1 * D
 2(2(2 * A + 1 * B) + 1 * C) + 1 * D

  == 2(2(2(1 * A) + 1 * B) + 1 * C) + 1 * D
 


*/
int NtoTen(string e, int N){
	int ans = 0;
	int len = e.length();
	int B = pow(N, len - 1);
	for (int i = 0; i < len; i++) {
		if ('0' <= e[i] && e[i] <= '9') {
			ans += (e[i] - '0') * B;
		}
		else {
			ans += (e[i] - 'A' + 10) * B;
		}
		B /= N;
	}
	return ans;
}
//N to N
string NtoN(string N, int from, int to) {
	string ans = "";
	if (from == 10) {
		ans =  tenToN(stoi(N), to);
	}
	else {
		auto tmp = NtoTen(N, from);
		cout << tmp << endl;
		ans = tenToN(tmp, to);
	}
	return ans;
}


int main() {
	cout << NtoN("1111A1F", 16, 2) << endl;











	return 0;
}