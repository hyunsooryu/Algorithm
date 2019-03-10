#include "pch.h"
#include <iostream>
#include <queue>
#include <map>
using namespace std;


//Way to get the answer -> 3 method;
//1.SAVE ALL THINGS IN SCREEN
//2.PASTE ALL THINGS IN CLIPBOARD TOWARD SCREEN -> we can easliy catch that pasting is the only way to make add in Screen
//3.ERASE ONE THING IN  SCREEN -> again, the only way to make negative in Screen
map<pair<int, int>, int> V;
//pair_first : now on screen
//pair_second : now in Clipboard
void BFS(int target) {
	queue<pair<int,int>> Q;
	V[make_pair(1, 0)] = 1;
	Q.push(make_pair(1, 0));
	
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		int onScreen = tmp.first;
		int onClipboard = tmp.second;

		if (onScreen == target) {
			cout << V[tmp] - 1 << endl;
			break;
		}
		// 1.
		if (onScreen > 0 && V[make_pair(onScreen, onScreen)] == 0) {
			V[make_pair(onScreen, onScreen)] = V[tmp] + 1;
			Q.push(make_pair(onScreen, onScreen));
		}
		// 2.
		if (onClipboard > 0 && V[make_pair(onScreen + onClipboard, onClipboard)] == 0) {
			V[make_pair(onScreen + onClipboard, onClipboard)] = V[tmp] + 1;
			Q.push(make_pair(onScreen + onClipboard, onClipboard));
		}
		// 3
		if (onScreen > 0 && V[make_pair(onScreen - 1, onClipboard)] == 0) {
			V[make_pair(onScreen - 1, onClipboard)] = V[tmp] + 1;
			Q.push(make_pair(onScreen - 1, onClipboard));
		}

	}
}

int main() {
	int S;
	cin >> S;
	BFS(S);














	return 0;
}