#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//FIRST DIMENSION 순간이동을 할 시는 0초이다. 이게 무슨 말이냐 하면, 순간이동이 가장 빠르다는것이다. 어떻게 작동해야할까. 우선순위 큐 or DEQ
int A[100001];
int D[100001];
int P[100001];
int N, K;
struct pair_cmp {
	bool operator()(const pair<int,int>& A, const pair<int,int>& B)const{
		return A.second > B.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> Q;



int main() {
	cin >> N >> K;
	
	D[N] = 1; //last ans - 1;

	Q.push(make_pair(N, D[N]));
	while (!Q.empty()) {
		auto tmp = Q.top();
		Q.pop();

		int pos = tmp.first;
		int time = tmp.second;
		//cout << pos << " 로 " << time << " 만에 이동 ";

		if (pos == K) {
			//cout << "!!!!발견!!!!";
			cout << D[K] - 1 << endl;
			break;
		}
		//cout << endl;

		if (pos - 1 >= 0 && D[pos - 1] == 0) {
			Q.push(make_pair(pos - 1, time + 1));
			D[pos - 1] = time + 1;
		}

		if (pos + 1 <= 100000 && D[pos + 1] == 0) {
			Q.push(make_pair(pos + 1, time + 1));
			D[pos + 1] = time + 1;
		}

		if (pos * 2 <= 100000 && D[pos * 2] == 0) {
			Q.push(make_pair(pos * 2, time));
			D[pos * 2] = time;
		}
	
	}
	














	return 0;
}