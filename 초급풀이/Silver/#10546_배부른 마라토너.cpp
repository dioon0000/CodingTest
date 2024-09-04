#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	map<string, int> m; //이름, 빈도
	string str;
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> str;
		if (m.find(str) != m.end())
			m[str]--;
	}

	for (auto iter : m) {
		if (iter.second > 0)
			cout << iter.first;
	}
	return 0;
}
