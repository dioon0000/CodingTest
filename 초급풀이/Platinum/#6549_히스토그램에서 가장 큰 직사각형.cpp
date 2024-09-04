//https://www.acmicpc.net/problem/6549
#include <bits/stdc++.h>
using namespace std;

long long h[100005];
stack<int> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		int n;
		long long ans = 0;
		cin >> n;
		s.push(0);

		if(!n)
			break;
		else{
			for(int i=1; i<=n; ++i){
				cin >> h[i];
			}

			for(int i=1; i<=n+1; ++i){
				while(!s.empty() && h[s.top()]>h[i]){
					int idx = s.top();
					s.pop();
					ans = max(ans, h[idx]*(i-s.top()-1));
				}
				s.push(i);
			}

			cout << ans << '\n';

			//배열과 스택 초기화
			memset(h, 0, sizeof(h));
			while(!s.empty())
				s.pop();
		}
	}
	return 0;
}