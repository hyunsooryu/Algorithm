#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;


char Start[] = {'[','{','(','<'};
char End[] = { ']','}',')','>'};
map<char, int> DIC;

string target;
bool isStart(char e) {
	for (int i = 0; i < 4; i++) {
		if (e == Start[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	auto flag = false;
	for (int i = 0; i < 4; i++) {
		DIC[Start[i]] = i;
		DIC[End[i]] = i;
	}
	cin >> target;
	stack<int, vector<int>> S;
	for (auto j : target) {
		if (j == ')' || j == '}' || j == '>' || j == ']') {
			if (S.empty()) {
				flag = true;
				break;
			}
			else if (!isStart(S.top())) {
				flag = true;
				break;
			}
			else {
				if (DIC[S.top()] == DIC[j]) {
					S.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}
		else {
			S.push(j);
		}
	}

	if (!S.empty() || flag == true) {
		cout << "WRONG " << endl;
	}
	else {
		cout << "GOOD" << endl;
	}



	//스택이 비었는데 ) } ] > 을 넣으려고 한다 X
	//스택의 top과 다른 괄호를 넣으려 한다 X
	//스택의 top과 같은 괄호이다. 0 짝이










	return 0;
}