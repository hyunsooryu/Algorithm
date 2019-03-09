#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> path;
map<vector<int>, bool> V;
vector<int> A;

void go(int i, int cnt){
    if(cnt == M){
      if(!V[path]){
        V[path] = true;
        for(auto j : path){
          cout << j << " ";
        }
        cout << endl;
      }
      return;
    }
    for(int k = i; k < N; k++){
        path.push_back(A[k]);
        go(k, cnt + 1);
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
        path.push_back(A[i]);
        go(i, 1);
        path.pop_back();
    }
















    return 0;
}