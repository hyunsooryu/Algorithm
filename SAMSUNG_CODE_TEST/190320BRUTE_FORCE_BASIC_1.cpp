#include <iostream>

using namespace std;
int E, S, M;
//E = 15 S = 28 M = 19
int main() {
	cin >> E >> S >> M;
	int i = 1;
	int j = 1;
	int k = 1;
	int year = 1;
	while (true) {
		if (i == E && j == S && k == M) {
			break;
		}
		cout << i << " " << j << " " << k << " : " << year << endl;
		i += 1;
		j += 1;
		k += 1;
		if (i == 16) {
			i = 1;
		}
		if (j == 29) {
			j = 1;
		}
		if (k == 20) {
			k = 1;
		}
		year++;
	}
	printf("%d", year);
	return 0;
}