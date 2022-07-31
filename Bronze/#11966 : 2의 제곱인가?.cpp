//https://www.acmicpc.net/problem/11966
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, val=1;
	bool flag = false;
	cin >> n;
	if(n == 1)
		cout << "1\n";
	else{
		while(val<n){
			val*=2;
			if(val == n){
				cout << "1\n";
				flag = true;
			}
		}
		if(!flag)
			cout << "0\n";
	}
	return 0;
}
