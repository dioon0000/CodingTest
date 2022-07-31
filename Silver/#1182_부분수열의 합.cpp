//BackTracking PS
#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt=0;
vector<int> v;

void DFS(int idx, int sum){
  if(idx >= n)
    return;
  if(sum+v[idx] == s)
    cnt++;
  
  DFS(idx+1, sum);
  DFS(idx+1, sum+v[idx]);
}

int main(){
  cin >> n >> s;
  for(int i=0; i<n; ++i){
    int tmp;
    cin >> tmp;
    v.push_back(tmp); 
  }

  DFS(0,0);
  cout << cnt;
  return 0;
}
