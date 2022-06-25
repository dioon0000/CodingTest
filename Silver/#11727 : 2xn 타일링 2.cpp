//https://www.acmicpc.net/problem/11727
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, div = 10007, dp[1001] ={0, };
	dp[1] = 1;	dp[2] = 3;
	cin >> n;

	for(int i=3; i<=n; ++i)
		dp[i] = (dp[i-1]+2*(dp[i-2])) % div;

	cout << dp[n];
	return 0;
}
