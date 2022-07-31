//https://www.acmicpc.net/problem/2693
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	vector<int> v;
	cin >> T;

	while(T--){
		int tmp;
		for(int i=0; i<10; ++i){
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end(), greater<int>());
		cout << v[2] << '\n';

		v.clear();
	}

	return 0;
}
