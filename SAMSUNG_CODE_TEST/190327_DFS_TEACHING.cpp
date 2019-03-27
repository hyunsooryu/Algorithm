#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
bool V[26];
using namespace std;
int N, K;
int MAX = 0;
vector<string> words;
int main() {
	cin >> N >> K;
	int target = 1;
	cout << target << endl;
	words.resize(N);
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		int length = temp.length();
		words[i] = temp.substr(4, length - 8);
		sort(words[i].begin(), words[i].end());
		cout << words[i] << endl;
	}
	if (K <= 4) {
		cout << 0 << endl;
		return 0;
	}
	else if (K == 26) {
		cout << N << endl;
		return 0;
	}
	else {
		if (K == 5) {
			int total = 0;
			for (auto j : words) {
				auto flag = false;
				for (auto k : j) {
					if (k != 'a' || k != 'n' || k != 't' || k != 'c' || k != 'i') {
						flag = true;
						break;
					}
				}
				if (!flag) {
					total += 1;
				}
			}
			cout << total << endl;
			return 0;
		}
		else {
			V['a' - 'a'] = true;
			V['c' - 'a'] = true;
			V['i' - 'a'] = true;
			V['t' - 'a'] = true;
			V['n' - 'a'] = true;
			vector<char> B = {'b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z'};
			for (auto j : B) {
				cout << j << " ";
			}
			cout << endl;
			vector<int> TMP;
			for (int i = 0; i < 21 - (K - 5); i++) {
				TMP.push_back(0);
			}
			for (int i = 0; i < (K - 5); i++) {
				TMP.push_back(1);
			}
			for (auto j : TMP) {
				cout << j << endl;
			}
			do {
				int total = 0;
				for (int i = 0; i < 21; i++) {
					if (TMP[i] == 1) {
						V[B[i] - 'a'] = true;
						cout << B[i] << " ";
					}
					else {
						V[B[i] - 'a'] = false;
					}
				}
				cout << endl;
				for (auto j : words) {
					cout << j << " ";
					auto flag = false;
					for (auto k : j) {
						if (!V[k - 'a']) {
							flag = true;
							break;
						}
					}
					if (flag) {
						continue;
					}
					else {
						total += 1;
					}
				}
				if (total > MAX) {
					MAX = total;
				}
			} while (next_permutation(TMP.begin(), TMP.end()));
		}
		
	}

	cout << MAX << endl;
	







	return 0;
}