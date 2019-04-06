#include <iostream>
#include <vector>
using namespace std;
vector<int> A[1001];
//방향이 없는 그래프가 주어졌을 때, 
//연결요소의 개수를 구하는 프로그램을 작성하시오.
//연결요소의 개수는 한번 씩 DFS/BFS를 통해 방문해주고, 방문하러 들어간 횟수를 더해주면된다.
int N, M, cnt;
bool check[1001];
void DFS(int n) {
	check[n] = true;
	for (auto j : A[n]) {
		if (!check[j]) {
			DFS(j);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			DFS(i);
			cnt += 1;
		}
	}

	cout << cnt << endl;








	return 0;
}