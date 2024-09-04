//https://www.acmicpc.net/problem/7568
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, weight, height;
	vector<pair<int, int>> v;

	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> weight >> height;
		v.push_back({weight, height});
	}

	for(int i=0; i<n; ++i){
		int rank = 1, cnt=0;
		for(int j=0; j<n; ++j){
			if(i == j)	continue;

			if(v[i].first < v[j].first && v[i].second < v[j].second)	cnt+=1;
		}
		cout << rank+cnt << ' ';
	}

	return 0;
}
