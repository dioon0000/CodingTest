#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int b, p;
	cin >> b;
	p = 5*b-400;

	if(p > 100)
		cout << p << '\n' << -1;
	else if(p < 100)
		cout << p << '\n' << 1;
	else
		cout << p << '\n' << 0;

	return 0;
}