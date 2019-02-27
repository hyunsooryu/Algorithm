#include "pch.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> ans;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int d = 0) { data = d, left = NULL, right = NULL;}
};

struct Tree {
	Node* root;
	string preOrderdata;
	Tree() :root(NULL), preOrderdata(""){}
	void insert(Node** p, int data) {
		if (*p == NULL) {
			*p = new Node(data);
		}
		else {
			if ((*p)->data > data) {
				if ((*p)->left == NULL) {
					(*p)->left = new Node(data);
				}
				else {
					insert(&(*p)->left, data);
				}
			}
			else {
				if ((*p)->right == NULL) {
					(*p)->right = new Node(data);
				}
				else {
					insert(&(*p)->right, data);
				}
			}
		}
	}

	void Preorder(Node* r) {
		if (r == NULL) {
			return;
		}
		if (r == root) {
			preOrderdata.push_back('A');
		}
		if (r->left != NULL) {
			preOrderdata.push_back('L');
			Preorder(r->left);
		}
		if (r->right != NULL) {
			preOrderdata.push_back('R');
			Preorder(r->right);
		}

	}
};


int main() {
	int N, C;
	cin >> N >> C;
	Tree* tree = new Tree[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < C; j++) {
			int x;
			cin >> x;
			tree[i].insert(&tree[i].root, x);
		}
		(tree + i)->Preorder((tree + i)->root);
		ans.insert((tree + i)->preOrderdata);
	}
	for (auto j : ans) {
		cout << j << endl;
	}
	return 0;
}
