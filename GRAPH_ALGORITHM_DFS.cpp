#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

vector<int> A[1001];
bool V[1001];

void make_edge(int from, int to) {
	A[from].push_back(to);
	A[to].push_back(from);
}

void __init__() {
	make_edge(1, 5);
	make_edge(1, 2);
	make_edge(2, 5);
	make_edge(2, 3);
	make_edge(3, 4);
	make_edge(4, 5);
	make_edge(4, 6);
}
//STACK USED
void DFS_S(int start_point) {
	stack<int, vector<int>> S;
	S.push(start_point);
	V[start_point] = true;
	while (!S.empty()) {
		auto tmp = S.top();
		cout << tmp << " ";
		S.pop();
		for (auto j : A[tmp]) {
			if (!V[j]) {
				V[j] = true;
				S.push(j);
			}
		}
	}
	cout << endl;
}

//RECURSIVE USED
void DFS_R(int point) {
	V[point] = true;
	cout << point << " ";
	for (auto j : A[point]) {
		if (!V[j]) {
			DFS_R(j);
		}
	}
}

int main() {
	__init__();
	DFS_R(1);
	cout << endl;  memset(V, false, sizeof(V));
	DFS_S(1);






	return 0;
}