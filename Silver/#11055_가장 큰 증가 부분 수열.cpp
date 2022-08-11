//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <algorithm>
#define MAX 1005
using namespace std;

int n, ans=0;
int arr[MAX], dp[MAX];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//INPUT Info
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	dp[0] = arr[0];

	//O(n^2)
	for(int i=1; i<n; ++i){
		dp[i] = arr[i];
		for(int j=i-1; j>=0; --j){
			//현재 값이 이전 값보다 크면서 현재 dp[i]값이 dp[j]+arr[i]보다 작다면 값을 변경해준
			if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
	}

	ans = *max_element(dp, dp+n);
	cout << ans;
	return 0;
}