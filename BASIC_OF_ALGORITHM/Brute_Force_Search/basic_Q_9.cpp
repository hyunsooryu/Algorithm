#include <iostream>
#include <algorithm>
using namespace std;
//CHAR IN DICTIONARY WAYS.
//(1M 2J && cnt == L) == POSSIBLE CONDITION
//OVER L IMPOSSIBLE
//(C c L) && POSSIBLE(1M 2J) // IN DICTIONARY WAYS
char P[15];
char A[15];
int mo = 0;
int ja = 0;
void cal(int i, int button) {
	if (button == 0) {
		if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	else {
		if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') {
			mo--;
		}
		else {
			ja--;
		}
	}
}
void go(int index, int start, int L, int C){ 
	if (index == L) {
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < index; i++) {
				cout << A[P[i]];
			}
			cout << endl;
		}
		return;
	}
	for (int i = start; i < C; i++) {
		P[index] = i;
		cal(i, 0);
		go(index + 1, i + 1, L, C);
		cal(i, 1);
	}
}

int main() {
	int L, C;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> A[i];
	}
	sort(A, A + C);
	go(0, 0, L, C);
	
	return 0;
}