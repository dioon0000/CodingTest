//https://www.acmicpc.net/problem/2075
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq; //Min heap
	int n, val, size=0;
	cin >> n;
	for(int i=0; i<n*n; ++i){
		cin >> val;
		if(size == n){
			if(val > pq.top()){
				pq.pop();
				pq.push(val);
			}
		}
		else{
			pq.push(val);
			size++;
		}
	}

	cout << pq.top();
	return 0;
}