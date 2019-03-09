#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> path;
map<vector<int>, bool> V;
vector<int> A;
bool impossible[10001];

void go(int i, int cnt){
    if(cnt == M && !V[path]){
        for(auto j : path){
            cout << j << " ";
        }
        cout << endl;
        V[path] = true;
    }
    for(int k = 0; k < N; k++){
        if(impossible[k]){
            continue;
        }
        path.push_back(A[k]);
        impossible[k] = true;
        go(k, cnt + 1);
        impossible[k] = false;
        path.pop_back();
    }
}

int main(){
    cin >> N >> M;
    A.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
  sort(A.begin(), A.end());
    for(int i = 0; i < N; i++){
        impossible[i] = true;
        path.push_back(A[i]);
        go(i, 1);
        path.pop_back();
        impossible[i] = false;
    }
















    return 0;
}