//https://www.acmicpc.net/problem/1654
#include <bits/stdc++.h>
using namespace std;

int k, n, len, x;
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for(int i=0; i<k; ++i){
		cin >> len;
		v.push_back(len);
	}

	//가장 길이가 긴 랜선값 찾기
	x = *max_element(v.begin(), v.end());

	long long left = 1, right = x, ans=0;
	while(left<=right){
		int res = 0;
		long long mid = (left+right)/2;

		for(int i=0; i<k; ++i)
			res+=v[i]/mid;

		if(res<n){
			right = mid-1;
		}
		else{
			ans = mid;
			left = mid+1;
		}
	}

	cout << ans << '\n';
	return 0;
}
