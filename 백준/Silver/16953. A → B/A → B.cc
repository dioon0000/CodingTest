#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, cnt=0;

	cin >> a >> b;
	while(a<b){
		if(b%10 == 1){
			b/=10;
			cnt++;
		}
		else{
			if(b%2==0){
				b/=2;
				cnt++;
			}
			else
				break;
		}
	}
	if(a==b)
		cout << cnt+1;
	else
		cout << -1;
	return 0;
}