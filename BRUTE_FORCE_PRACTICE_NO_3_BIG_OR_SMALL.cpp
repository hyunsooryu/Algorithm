#include <iostream>
#include <string>
#include <vector>

using namespace std;
string target;
int N;
long long MAX = -1;
long long MIN = -1;
bool V[10];

long long calculate(long long e, int digit) {
	return e * int(pow(10, N + 1 - digit));
}

bool isPossible(int N, int base, int compare){
	if (V[N]) {
		return false;
	}
	if (target[compare] == '<') {
		return N > base;
	}
	return N < base;
}


void go(int i, int cnt, long long sum) {
	if (cnt == N + 1) {
		if (sum > MAX || MAX == -1) {
			MAX = sum;
		}
		if (sum < MIN || MIN == -1) {
			MIN = sum;
		}
		return;
	}
	int BASIC = i;
	for (int k = 0; k < 10; k++) {
		if (isPossible(k, BASIC, cnt - 1)) {
			V[k] = true;
			go(k, cnt + 1, sum + calculate(k, cnt + 1));
			V[k] = false;
		}
	}
}


int main() {
	cin >> N;
	cin >> target;
	

	for (int i = 0; i < 10; i++) {
		V[i] = true;
		go(i, 1, calculate(i, 1));
		V[i] = false;
	}

	cout << MAX << endl;
	cout << MIN << endl;



	return 0;
}
