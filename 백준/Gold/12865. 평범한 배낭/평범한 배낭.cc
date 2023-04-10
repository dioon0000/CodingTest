#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)
	int n, k, w, v;
	//pair에는 각각 무게 W(1 ≤ W ≤ 100,000)와 가치 V(0 ≤ V ≤ 1,000)가 주어진다
	vector<pair<int, int>> vec;
	cin >> n >> k;
	//i번째 물건을 담을때의 최대 가치 dp vector
	vector<vector<int>> knapsack(n+1);
	//각 물건의 무게와 가치를 저장할 for문
	vec.push_back({0,0});
	for(int i=0; i<n; ++i){
		cin >> w >> v;
		vec.push_back({w,v});
	}
	//kanpsack 이차원 배열을 채울 이중 for문
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=k; ++j){
			if(i==0)
				knapsack[i].push_back(0);
			else{
				if(vec[i].first > j){
					knapsack[i].push_back(knapsack[i-1][j]);
				}
				else{
					knapsack[i].push_back(max(vec[i].second + knapsack[i-1][j-vec[i].first], knapsack[i-1][j]));
				}
			}
		}
	}
	cout << knapsack[n][k];
	return 0;
}