#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> v;
	string str;
	cin >> str;
	
	int len = str.length();
	for (int i = 0; i < len; ++i) {
		v.push_back(str.substr(i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < len; ++i) {
		cout << v[i] << '\n';
	}
	return 0;
}