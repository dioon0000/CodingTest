//https://www.acmicpc.net/problem/11053
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
	//arr[0]의 값은 무조건 증가하는 부분수열이기 때문에 초기값을 1로 초기화
	dp[0] = 1; 

	//각 자릿수에서 최대 부분수열을 저장하는 dp를 생성하는 for문
	//i-1부터 0까지 Arr[i]보다 작은 값에서 dp[j]+1값이 dp[i]보다 크다면 현재 dp[i]의 값을 변경하여 준다
	for(int i=1; i<n; ++i){
		dp[i] = 1;
		for(int j=i-1; j>=0; --j){
			if(arr[i] > arr[j]){
				if(dp[j]+1 > dp[i])
					dp[i] = dp[j]+1;
			}
		}
	}

	ans = *max_element(dp, dp+n);
	cout << ans;
	return 0;
}