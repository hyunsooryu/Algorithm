#include <iostream>

using namespace std;

/*
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다. 
1 ~ 9 : 9 * 1
10 ~ 99 : 2 * 90
 86

 86 - 10 = <76 + 1>
100 ~ 999: 3 * 900
1000 ~ 9999:  4 * 9000

1 * 1 * 9
2 * 10 * 9
3 * 100 * 9
*/

int getDigit(int N) {
	int tmp = N;
	int digit = 0;
	int t = 1;
	int g = 9;
	int r = 1;
	int cnt = 0;
	while (tmp > 0) {
		tmp /= 10;
		digit += 1;
		if (tmp != 0) {	//0일때는 더하지않는다. 계산의 편리성을 위해
			cnt += (t * g * r);
		}
		t += 1;
		r *= 10;
	}
	int add = N - int(pow(10, digit - 1)) + 1; //마지막 단위에 대한 계산을 진행해준다.
	cnt += (add * digit); //추가해준다.
	return cnt;
}

int main() {
	cout << getDigit(120) << endl;












	return 0;
}