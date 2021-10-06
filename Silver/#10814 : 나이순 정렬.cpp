#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, string> &a, const pair<int, string> &b){
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int num;
  vector<pair<int, string>> v;
  cin >> num;
  for(int i=0; i<num; ++i){
    pair<int, string> tmp;

    cin >> tmp.first >> tmp.second;
    v.push_back(tmp);
  }
  //같은 나이일 때는 sort함수를 사용하면 불안정 정렬 상태가 되므로 stable_sort를 사용
  //stable_sort : 조건이 같은 상황일 때는 항상 원래 순서를 유지하는 정렬 방식
  stable_sort(v.begin(), v.end(), cmp);

  for(int i=0; i<num; ++i)
    cout << v[i].first << " " << v[i].second << '\n';
}