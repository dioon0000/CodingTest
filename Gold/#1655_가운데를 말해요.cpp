#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> s; //내림차순
priority_queue<int, vector<int>, greater<int>> b;  //오름차순

void Answer_Mid_Value(int tmp){
  if(s.empty()) s.push(tmp);
  else{
    if(tmp < s.top()) s.push(tmp);
    else  b.push(tmp);
    
    if(s.size()>b.size()){
      b.push(s.top());
      s.pop();
    }
    if(b.size()>s.size()){
      s.push(b.top());
      b.pop();
     }
  }
  cout << s.top() << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, tmp;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> tmp;
    Answer_Mid_Value(tmp);
  }
  return 0;
}
