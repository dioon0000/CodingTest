#include <iostream>
using namespace std;

int dp[41] = {0};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  dp[0] = 1;
  for(int i=2; i<=41; i++){
    dp[i] = dp[i-1]+dp[i-2];
  }

  int t;
  cin >> t;
  while(t--){
    int x;
    cin >> x;

    cout << dp[x] << " " << dp[x+1] << '\n';
  }
  return 0;
}