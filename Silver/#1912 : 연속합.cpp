https://www.acmicpc.net/problem/1912
#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, arr[MAX], dp[MAX];

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> arr[i];

	dp[0] = arr[0];
	for(int i=1; i<n; ++i)
		dp[i] = max(dp[i-1]+arr[i], arr[i]);

	m = dp[0];
	for(int i=0; i<n; ++i)
		if(dp[i] > m)
			m = dp[i];

	cout << m;
	return 0;
}
