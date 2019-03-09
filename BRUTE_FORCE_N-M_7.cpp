#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> path;
vector<int> A;
int N, M;

void go(int i, int cnt){
  if(cnt == M){
      for(auto j : path){
        cout << A[j] << " ";
      }
      cout << endl;
      return;
  }
  for(int k = 0; k < N; k++){
    path.push_back(k);
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
    path.push_back(i);
    go(i, 1);
    path.pop_back();
  }




  return 0; 
}