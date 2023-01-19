#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, m, cnt=0;
		string str;
		cin >> n >> m;
		for(int i=n; i<=m; ++i){
			str = to_string(i);
			for(int j=0; j<str.length(); ++j){
				if(str[j] == '0')
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}