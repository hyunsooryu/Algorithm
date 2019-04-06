//BFS
//모든 가중치가 1일때, 최단거리 알고리즘이 되게 됩니다.
//BFS는 단계별로 진행이 되기 때문에, 가중치가 1일때 최단거리를 구하는 알고리즘이됩니다.
//DFS를 통해서는 최단거리를 구할 수 없어요~
#include <iostream>
#include <queue>
using namespace std;
//3가지 연산을 통해 이모티콘 S개를 만들어 낼 수 있다.
//화면에 있는 이모티콘을 모두 복사. 클립보드에 저장
//클립보드에 있는 모든 이모티콘을 화면에 복붙.
//화면에 있는 이모티콘중 하나를 삭제
//모든 연산은 1초가 걸린다. //BFS힌트
//클립보드가 비어있는 상태에서는 붙여넣기 no
int S;
int V[1001][1001];
//화면값 + 클립보드 값을 동시에 저장해서 보내야한다.
int main() {
	cin >> S;
	int start = 1;
	queue<pair<int, int>> Q;
	V[start][0] = 1;
	Q.push(make_pair(start, 0));
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int screen = tmp.first;
		int clipBoard = tmp.second;
        cout << V[screen][clipBoard] << endl;
		//cout << screen << " " << clipBoard << endl;
		if (screen == S) {
			cout << V[screen][clipBoard] - 1 << endl;
			break;
		}
		//screen copy
		if (V[screen][screen] == 0) {
			V[screen][screen] = V[screen][clipBoard] + 1;
			Q.push(make_pair(screen, screen));
		}
		//clipboard copy
		if (clipBoard > 0 && V[screen + clipBoard][clipBoard] == 0) {
			V[screen + clipBoard][clipBoard] = V[screen][clipBoard] + 1;
			Q.push(make_pair(screen + clipBoard, clipBoard));
		}
		//erase screens one
		if (screen > 0 && V[screen - 1][clipBoard] == 0) {
			V[screen - 1][clipBoard] = V[screen][clipBoard] + 1;
			Q.push(make_pair(screen - 1, clipBoard));
		}
	}












	return 0;
}