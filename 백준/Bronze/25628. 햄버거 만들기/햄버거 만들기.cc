#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, y, ans=0;
	cin >> x >> y;
	if(x/2 <= y)
		cout << x/2;
	else{
		if(x/2 < 2)
			cout << 0;
		else
			cout << y;
	}
	return 0;
}