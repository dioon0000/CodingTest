#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<int> ms; //Default 오름차순
    int t, k, value;
    char oper;
    cin >> t;
    //TestCase
    while(t--){
      cin >> k;
      //연산처리 개수 k
      while(k--){
        cin >> oper >> value;
        if(oper == 'I'){
          ms.insert(value);
        }
        else if(oper == 'D'){
          //1일 때 최댓값을 삭제 (가장 뒤에 값을 삭제함)
          if(!ms.empty() && value == 1){
            auto iter = ms.end();
            iter--;
            ms.erase(iter);
          }
          //-1일 때 최솟값을 삭제 (가장 앞에 값을 삭제함)
          else if(!ms.empty() && value == -1){
            ms.erase(ms.begin());
          }
        }
      }
      if(ms.empty())  cout << "EMPTY" << '\n';
      else{
        auto end_iter = ms.end();
        auto start_iter = ms.begin();
        end_iter--;
        cout << *end_iter << " " << *start_iter << '\n';
      }
      ms.clear();
    }
    return 0;
}
