#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    long long sum=0, value=0, first, second;
    priority_queue<int, vector<int>, greater<int>> q; //front에 가장 작은 값

    cin >> n;
    for(int i=0; i<n; i++){
      cin >> tmp;
      q.push(tmp);
    }

    if(q.size() == 1){
      cout << 0;
      return 0;
    }
    
    while(!q.empty()){
      //카드 묶음이 하나일때
      if(q.size() == 1){
        sum+=q.top();
        q.pop();
      }
      else{
        //가장 작은 두 카드 묶음을 선별함
        first = q.top();
        q.pop();
        second = q.top();
        q.pop();

        value = first+second;
        sum+=value;
        if(!q.empty())  q.push(value);
        value = 0;
      }
    }

    cout << sum;
    return 0;
}
