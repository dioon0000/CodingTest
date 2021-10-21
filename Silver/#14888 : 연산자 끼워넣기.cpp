#include <iostream>
#define MAX 11
using namespace std;

int n;
int arr[MAX];
int operators[4];
int myMin = 1000000001;
int myMax = -1000000001;

void solution(int cnt, int tmp){

  if(cnt == n-1){
    if(tmp > myMax)
      myMax = tmp;
    if(tmp < myMin)
      myMin = tmp;
    return;
  }

  for(int i=0; i<4; ++i){
    if(operators[i] > 0){
      operators[i]--;
      if(i == 0)
        solution(cnt+1, tmp+arr[cnt+1]);
      else if(i == 1)
        solution(cnt+1, tmp-arr[cnt+1]);
      else if(i == 2)
        solution(cnt+1, tmp*arr[cnt+1]);
      else if(i == 3)
        solution(cnt+1, tmp/arr[cnt+1]);
      operators[i]++;
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  //n input
  cin >> n;
  //Sequence input
  for(int i=0; i<n; ++i)
    cin >> arr[i];  
  //Operator input
  for(int i=0; i<4; ++i)
    cin >> operators[i];

  solution(0, arr[0]);
  cout << myMax << '\n' << myMin;
}