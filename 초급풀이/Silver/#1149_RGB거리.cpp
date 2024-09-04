//https://www.acmicpc.net/problem/1149
#include <bits/stdc++.h>
#define R 0
#define G 1
#define B 2
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp;
	int cost[3] ={0, }; //각 집마다의 R, G, B비용
	cin >> n;
	vector<vector<int>> v(n+1, vector<int>(3)); //누적비용을 저장할 이차원 벡터
	v[0][R] = 0;
	v[0][G] = 0;
	v[0][B] = 0;
	
	for(int i=1; i<=n; ++i){
		//i번째 집의 RGB비용
		cin >> cost[R] >> cost[G] >> cost[B];
		//누적비용 계산 DP (min Func : O(n))
		v[i][R] = min(v[i-1][G], v[i-1][B]) + cost[R];
		v[i][G] = min(v[i-1][R], v[i-1][B]) + cost[G];
		v[i][B] = min(v[i-1][R], v[i-1][G]) + cost[B];
	}

	cout << min(v[n][R], min(v[n][G], v[n][B]));
	return 0;
}
