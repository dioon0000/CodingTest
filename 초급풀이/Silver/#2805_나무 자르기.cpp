//https://www.acmicpc.net/problem/2805
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, tmp;
	vector<int> tree;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> tmp;
		tree.push_back(tmp);
	}

	int start = 0;
	int end = *max_element(tree.begin(), tree.end());
	int ans = 0;

	while(start<=end){
		long long int tot = 0;
		int mid = (start+end)/2;

		for(int i=0; i<n; ++i)
			if(tree[i] > mid)	tot+=tree[i]-mid;

		if(tot < m)	end = mid-1;
		else{
			ans = mid;
			start = mid+1;
		}
	}

	cout << ans << '\n';
	return 0;
}
