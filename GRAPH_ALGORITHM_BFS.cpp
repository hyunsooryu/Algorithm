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
//Queue Used

void BFS(int point) {
	queue<int> Q;
	V[point] = true;
	Q.push(point);
	while (!Q.empty()) {
		auto tmp = Q.front();
		cout << tmp << " ";
		Q.pop();
		for (auto j : A[tmp]) {
			if (!V[j]) {
				V[j] = true;
				Q.push(j);
			}
		}
	}
}

int main() {
	__init__();
	BFS(1);
	
	






	return 0;
}