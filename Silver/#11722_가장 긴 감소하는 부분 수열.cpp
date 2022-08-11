//https://www.acmicpc.net/problem/11722
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[MAX], dp[MAX];
	int n, ans=0;

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	dp[0] = 1;

	for(int i=1; i<n; ++i){
		dp[i] = 1;
		for(int j=i-1; j>=0; --j){
			if(arr[i] < arr[j]){
				if(dp[j]+1 > dp[i])
					dp[i] = dp[j]+1;
			}
		}
	}

	ans = *max_element(dp, dp+n);
	cout << ans;
	return 0;
}