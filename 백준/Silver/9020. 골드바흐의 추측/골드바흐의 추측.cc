#include <iostream>
#include <cmath>
#define MAX 10001
using namespace std;

int main(){
  int n, t;
  bool prime[MAX];

  fill_n(prime, MAX, 1);
  prime[0] = false, prime[1] = false;

  cin >> t;
  //각 테스트케이스 별 골드바흐 수를 나타내기 위한 for문
  for(int i=0; i<t; i++){
    cin >> n;
    
    //변수 n을 max값으로 잡아 에라스토테네스의 체 식을 이용한다
    for(int j=2; j<= sqrt(n); j++){
      if(prime[j]==true)
        for(int k=j*2; k<=n; k+=j)
          prime[k] = false;
    }
    
    //n을 2로 나눈 구간부터 +- 1씩 소수가 되는 수인지 체크 한 뒤 가장 먼저 소수의 합으로 이루어진 n값이 나오는 것이 두 소수의 차가 가장 작은 수
    for(int l=n/2; l>0; l--){
      if(prime[l] && prime[n-l]){
        cout << l << " " << n-l << "\n";
        break;
      }
    }
  }
  return 0;
}