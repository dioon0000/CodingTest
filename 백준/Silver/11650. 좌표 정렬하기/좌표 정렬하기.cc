#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, x, y;
  vector<pair<int,int>> v;

  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> x >> y;
    v.push_back({x, y}); //v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; ++i){
    cout << v[i].first << " " << v[i].second << '\n';
  }
  return 0;
}