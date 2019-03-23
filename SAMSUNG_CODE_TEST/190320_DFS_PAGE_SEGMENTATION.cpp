#include <iostream>
#include <string>
using namespace std;
int N, M;
string A[4];
bool V[4][4];
int MAX;

void go(int n, int sum) {
	//cout << n << sum << endl;
	if (n == N * M) {
		if(sum > MAX){
			MAX = sum;
		}
	
		return;
	}
	if (V[n / M][n % M]) {
		go(n + 1, sum);
	}
	int pos_i = n / M;
	int pos_j = n % M;
	string temp = "";
	bool flag_r = false;
	for (int i = pos_i; i < N; i++) {
		if (V[i][pos_j]) {
			flag_r = true;
			for (int k = pos_i; k < i; k++) {
				V[k][pos_j] = false;
			}
			break;
		}
		V[i][pos_j] = true;
		temp.push_back(A[i][pos_j]);
		go(n + 1, sum + stoi(temp));
	}
	if (!flag_r) {
		for (int i = pos_i; i < N; i++) {
			V[i][pos_j] = false;
		}
	}
	
	bool flag_c = false;
	temp = "";
	for (int j = pos_j; j < M; j++) {
		if (V[pos_i][j]) {
			flag_c = true;
			for (int k = pos_j; k < j; k++) {
				V[pos_i][k] = false;
			}
			break;
		}
		V[pos_i][j] = true;
		temp.push_back(A[pos_i][j]);
		go(n + 1, sum + stoi(temp));
	}
	if (!flag_c) {
		for (int j = pos_j; j < M; j++) {
			V[pos_i][j] = false;
		}
	}



}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	go(0, 0);
	cout << "ANS" << endl;
	cout << MAX << endl;
	cout << "____" << endl;


	return 0;
}