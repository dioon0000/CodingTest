#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, start, end, tmp=0;

  cin >> t;
  for(int i=0; i<t; i++){
    bool flag = false, e_flag = false;
    string s, func;
    vector<int> v;
    cin >> func;
    cin >> n;
    cin >> s;

    //s에서 정수만 dq에 넣기
    for(int j=1; j<s.size(); j++){
      //s[j]의 값이 자연수 일때
      if(s[j] >='0' && s[j] <='9'){
        tmp*=10;
        tmp+=(s[j]-48);
      }
      else{
        v.push_back(tmp);
        tmp = 0;
      }
    }

    //func에 있는 값을 체크하여 R과 D동작 시행
    start = 0;
    end = n;
    for(int j=0; j<func.size(); j++){
      if(func[j] == 'R'){
        flag^=1; //비트연산자 ^: xor
        //int flag = 0 (flag+=1; flag%=2) : int형으로 flag를 사용하고 싶을 때
      }
      else{
        //flag == true 일때 end값을 움직여줌
        if(flag == true)
          end--;
        else
          start++;
      }
      if(start>end){
        e_flag=1;
      }
    }

    //출력
    if(e_flag == true){
      cout << "error" << '\n';
      continue;
    }
    if(start==end){
      cout << "[]\n";
      continue;
    }
    if(flag == false){
      cout << '[';
      for(int j=start; j<end; j++){
        if(j != end-1)
          cout << v[j] << ',';
        else
          cout << v[j] << ']' << '\n';
      }
    }
    else{
      cout << '[';
      for(int j=end-1; j>=start; j--){
        if(j != start)
          cout << v[j] << ',';
        else
          cout << v[j] << ']' << '\n';
      }
    }
  }
  return 0;
}
