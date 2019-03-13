#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int D[101][5];
int MAX[101];
/*    1  2  3   4
1선택  0  1  2   3
2버퍼  0  0  1   2
3출력  1  2  3   4
4복붙  0  0  0   D[1]'s MAX + D[3][1]
최대  1  2  3
*/
void Go(int N) {
	D[1][3] = 1;
	MAX[1] = 1;
	for (int i = 1; i <= N; i++) {
		cout << i << " : ";
		D[i][1] = D[i - 1][3];
		D[i][2] = D[i - 1][1];
		D[i][3] = D[i - 1][3] + 1;
		if (i >= 4) {
			D[i][4] = D[i - 3][3] + D[i - 1][2];
			int j = i;
			while (j - 3 >= 0) {
				int diff = i - j + 1;
				auto tmp = D[j - 3][3] + D[j - 1][2] * (diff);
				if (tmp > D[i][4]) {
					D[i][4] = tmp;
				}
				j -= 1;
			}
		}
		D[i][3] = max(D[i][3], D[i][4]);
		cout << D[i][1] << " " << D[i][2] << " " << D[i][3] << " " << D[i][4] << endl;
	}
}

int main() {


	Go(100);










	return 0;
}