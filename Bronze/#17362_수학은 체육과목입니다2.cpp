#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans;
	cin >> n;
	ans=n%8;
	
	if(ans == 1)
		cout << '1';
	else if(ans == 0 || ans == 2)
		cout << '2';
	else if(ans == 3 || ans == 7)
		cout << '3';
	else if(ans == 4 || ans == 6)
		cout << '4';
	else
		cout << '5';
	return 0;
}