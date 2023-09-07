#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> dp(n); //2차원 vector
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<=i; ++j){
			int x;
			cin >> x;
			dp[i].push_back(x);
		}

    //DP 알고리즘의 최적의 원칙을 활용한 풀이방법
	for(int i=n-2; i>=0; --i)
		for(int j=0; j<=i; ++j)
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+dp[i][j];

	cout << dp[0][0];
	return 0;
}