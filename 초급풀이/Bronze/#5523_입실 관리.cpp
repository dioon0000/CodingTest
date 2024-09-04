#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string>v(n);

	for(int i=0; i<n; ++i){
		cin >> v[i];
		transform(v[i].begin(), v[i].end(), v[i].begin(), ::tolower);
	}

	for(int i=0; i<n; ++i)
		cout << v[i] << '\n';

	return 0;
}