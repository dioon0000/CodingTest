//https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;
int dp[10] ={0, };

void solve(int n){
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	for(int i=3; i<n; ++i)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	cout << dp[n-1] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		solve(n);
	}
	return 0;
}
