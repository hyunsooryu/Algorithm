#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
bool VISITED[(1 << 9) - 1];
int solution(vector<vector<string>> relation) {
	int answer = 0;
	int row = relation.size();
	int col = relation[0].size();
	
	for (int S = 1; S <= (1 << col) - 1; S++) {
		map<int, bool> V;
		map <vector<string>, bool > DIC;
		for (int i = 0; i < 4; i++) {
			if (S & (1 << i)) {
				cout << i << ", ";
			}
		}
		cout << " 검사 들어감" << endl;


		//S 확인
		auto flag = false;
		auto p = S - 1;
		while (p >= 1) {
			if ((S & p) && (VISITED[p])) {
				cout << "현재 타겟인 " << S << "부분집합에 " << p << "가 이미 있습니다." << endl;
				flag = true;
				break;
			}
			p--;
		}
		if (flag) {
			continue;
		}

		for (int i = 0; i < col; i++) {
			if (S & (1 << i)) {
				V[i] = true;
			}
		}
		auto flag2 = false;
		for (int j = 0; j < row; j++) {
			vector<string> data;
			for (int k = 0; k < col; k++) {
				if (V[k] == true) {
					data.push_back(relation[j][k]);
				}
			}
			if (DIC[data] == true) {
				cout << "이미 같은 자료가 존재합니다. 아쉽게도 후보키가 될 수 없습니다." << endl;
				cout << "같은 값: ";
				for (auto j : data) {
					cout << j << " ";
				}
				cout << endl;
				flag2 = true;
				break;
			}
			else {
				DIC[data] = true;
			}
		}

		if (!flag2) {
			
			for (int i = 0; i < 4; i++) {
				if (S & (1 << i)) {
					cout << i << ", ";
				}
			}
			cout << " 는 후보키가 될 수 있습니다." << endl;
			answer += 1;
			VISITED[S] = true;
		}
	}
	return answer;
}

int main() {

	vector<vector<string>>  target = {{"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"}};

	cout << solution(target);







	return 0;
}