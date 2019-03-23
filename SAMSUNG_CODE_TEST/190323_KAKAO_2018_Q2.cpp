#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
using namespace std;
map<int, bool> V;

struct pair_cmp{
	bool operator()(pair<int,float> A, pair<int,float> B)const{
		if (A.second == B.second) {
			return A.first > B.first;
		}
		return A.second < B.second;
	}
};
vector<int> solution(int N, vector<int> stages) {
	priority_queue<pair<int, float>, vector<pair<int, float>>, pair_cmp> Q;
	vector<int> answer;
	sort(stages.begin(), stages.end());
	
	for (int j = 1; j <= N; j++) {
		auto itor = equal_range(stages.begin(), stages.end(), j);
		float dodal = itor.second - itor.first;
		float over = stages.end() - itor.second;
		cout << j << "  " << dodal << "   " << over << endl; 
		Q.push(make_pair(j, dodal / over));
	}
	while (!Q.empty()) {
		answer.push_back(Q.top().first);
		Q.pop();
	}
	return answer;
}

int main() {
	vector<int>target = {2,1,2,6,2,4,3,3};
	auto tmp = solution(5, target);
	for (auto j : tmp) {
		cout << j << " ";
	}
	cout << endl;
	






	return 0;
}