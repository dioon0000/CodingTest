#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	vector<int> v;
	getline(cin, str);
	for(int i=0; i<str.length(); ++i){
		if(str[i]>=48 && str[i]<=57){
			v.push_back(str[i]-48);
		}
	}

	if(v[0] + v[1] == v[2])
		cout << "YES";
	else
		cout << "NO";
	return 0;
}