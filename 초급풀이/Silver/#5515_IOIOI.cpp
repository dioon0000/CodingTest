//https://www.acmicpc.net/problem/5525
#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool flag = false;
	int n, m, cnt=0, ans=0;
	string s;

	cin >> n >> m;
	//s 문자열을 생성하는 for문
	for(int i=0; i<m; ++i){
		char x;
		cin >> x;
		s.push_back(x);
	}

	//s 문자열에서 Pn 문자열을 찾는 for문
	for(int i=0; i<m-2; ++i){
		if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I'){
			flag = true;
			cnt++;
		}
		else if(s[i] == 'O' && s[i+1] == 'I' && s[i+2] == 'O'){
			continue;
		}
		else{
			if(n<=cnt)
				ans += cnt-(n-1);
			cnt=0;
			flag = false;
		}
	}
	if(flag){
		if(n<=cnt)
			ans += cnt-(n-1);
	}

	cout << ans;
	return 0;
}
