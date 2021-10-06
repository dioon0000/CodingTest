#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  stack<char> oper;
  cin >> str;
  for(int i=0; i<str.length(); i++){
    //피연산자일 경우
    if(str[i] >= 'A' && str[i] <= 'Z'){
      cout << str[i];
    }
    //연산자(* or /)일 경우
    else if(str[i] == '*' || str[i] == '/'){
      while(!oper.empty() && (oper.top() == '*' || oper.top() == '/')){
        cout << oper.top();
        oper.pop();
      }
      oper.push(str[i]);
    }
    //연산자(+ or -)일 경우
    else if(str[i] == '+' || str[i] == '-'){
      while(!oper.empty() && oper.top() != '('){
        cout << oper.top();
        oper.pop();
      }
      oper.push(str[i]);
    }
    //여는 괄호일 경우
    else if(str[i] == '(')
      oper.push(str[i]);
    //닫는 괄호일 경우
    else if(str[i] == ')'){
      while(!oper.empty() && oper.top() != '('){
        cout << oper.top();
        oper.pop();
      }
      //여는 괄호를 pop
      oper.pop();
    }
  }
  
  //Stack에서 나머지 값을 모두 꺼냄
  while(!oper.empty()){
    cout << oper.top();
    oper.pop();
  }
  return 0;
}