#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> A;
vector<int> path;
void go(int i, int cnt){
  if(cnt == 2){
    for(auto j : path){
      cout<< A[j] << " ";
    }
    cout << endl;
    return;
  }

  for(int j = i + 1; j < N; j++){
    path.push_back(j);
    go(j, cnt + 1);
    path.pop_back();
  }
}

void go_linear(int i, int cnt){
  if(i >= N ||cnt == M){
    if(cnt == M){
      for(auto j : path){
        cout << A[j] << " ";
      }
      cout << endl;
    }
    return;
  }
  path.push_back(i);
  go_linear(i + 1, cnt + 1);
  path.pop_back();

  go_linear(i + 1, cnt);

}

int main(){
  cin >> N >> M;
  A.resize(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  sort(A.begin(), A.end());

/*
  for(int i = 0; i < N; i++){
    path.push_back(i);
    go(i, 1);
    path.pop_back();
  }
*/

go_linear(0, 0);











  return 0; 
}