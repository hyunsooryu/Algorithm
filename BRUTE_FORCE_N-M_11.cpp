#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
int SIZE;
bool V[10000];
vector<int> A;
vector<int> path;
void go(int i, int cnt){
  if(cnt == M){
    for(auto j : path){
      cout << j << " ";
    }
    cout << endl;
    return;
  }

  for(int k = 0; k < SIZE; k++){
    path.push_back(A[k]);
    go(k, cnt + 1);
    path.pop_back();
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int x;
    cin >> x;
    if(!V[x]){
      V[x] = true;
      A.push_back(x);
    }
  }
  SIZE = A.size();

  sort(A.begin(), A.end());
  for(int i = 0; i < SIZE; i++){
    path.push_back(A[i]);
    go(i, 1);
    path.pop_back();
  }


  

















  return 0;
}