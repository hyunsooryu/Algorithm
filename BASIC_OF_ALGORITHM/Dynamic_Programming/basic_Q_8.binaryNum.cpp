#include <iostream>
using namespace std;
//N자리 이친수라 하면  
/*
D[N][0] = D[N - 1][0] + D[N - 1][1]
D[N][1] = D[N - 1][0]
*/
long long D[91][2];
int main() {
	int N;
	cin >> N;
	D[1][0] = 0;
	D[1][1] = 1;
	for (int i = 2; i <= 90; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}
	cout << D[N][0] + D[N][1] << endl;







	return 0;
}