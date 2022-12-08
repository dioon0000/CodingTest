#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string str;
	cin >> n;
	cin >> str;
	for(auto iter=str.end()-5; iter!=str.end(); ++iter)
		cout << *iter;
	return 0;
}