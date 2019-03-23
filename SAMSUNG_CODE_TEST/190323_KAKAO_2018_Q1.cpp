#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, string> DIC;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string> ORDER;
	vector<string> ID;
	vector<string> NAME;
	for (auto j : record) {
		vector<string> temp;
		int s = 0;
		int e = 0;
		while (e < j.length()) {
			if (j[e] == ' ') {
				temp.push_back(j.substr(s, e - s));
				s = ++e;
			}
			else {
				e += 1;
			}
		}
		temp.push_back(j.substr(s, e - s));
		if (temp.size() == 2) { // leave
			ORDER.push_back(temp[0]);
			ID.push_back(temp[1]);
			cout << temp[0] << " " << temp[1] << endl;
		}
		if (temp.size() == 3) {//change Enter
			ORDER.push_back(temp[0]);
			ID.push_back(temp[1]);
			DIC[temp[1]] = temp[2];
			cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
		}
	}
	for (int i = 0; i < ORDER.size(); i++) {
		if (ORDER[i] == "Enter") {
			answer.push_back(DIC[ID[i]] + "님이 들어왔습니다.");
		}
		else if (ORDER[i] == "Leave") {
			answer.push_back(DIC[ID[i]] + "님이 나갔습니다.");
		}
		else {
			continue;
		}
	}
	return answer;
}

int main() {
	vector<string> A = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
	for (auto j : solution(A)) {
		cout << j << endl;
	}










	return 0;
}