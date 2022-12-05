#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, c;
		cin >> n >> c;
		if(n%c != 0)
			cout << n/c+1 << '\n';
		else
			cout << n/c << '\n';
	}
	return 0;
}