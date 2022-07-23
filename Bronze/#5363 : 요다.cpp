//https://www.acmicpc.net/problem/5363
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	for (int i=0; i<n; ++i){
		string str;
		vector<string> v;

		getline(cin, str);
		stringstream s(str);
		string word;
		while (s>>word){
			v.push_back(word);
		}

		for (int j=2; j<v.size(); ++j)
			cout << v[j] << " ";
		cout << v[0] << " " << v[1] << '\n';
	}
	return 0;
}
