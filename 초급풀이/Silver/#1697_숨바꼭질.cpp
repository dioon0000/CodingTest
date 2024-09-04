//1차원 BFS
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int dist[MAX];
queue<int> q;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, cnt = 1;
	cin >> n >> k;

	fill(dist, dist+MAX, -1);
	dist[n] = 0;
	q.push(n);

	while(dist[k] == -1){
		int cur = q.front();	q.pop();
		for(int nx : {cur-1, cur+1, cur*2}){
			if(nx < 0 || nx >= MAX)	continue;
			if(dist[nx] != -1)	continue;
			dist[nx] = dist[cur]+1;
			q.push(nx);
		}
	}

	cout << dist[k];
	return 0;
}
