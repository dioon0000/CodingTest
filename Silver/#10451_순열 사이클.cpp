//https://www.acmicpc.net/problem/10451
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int n;
int graph[MAX][MAX];
int vis[MAX];

void DFS(int node){
	for(int i=1; i<=n; ++i){
		if(graph[node][i] == 1){
			if(!vis[i]){
				vis[i] = 1;
				DFS(i);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int x, ans=0;
		memset(graph, 0, sizeof(graph));
		memset(vis, 0, sizeof(vis));
		cin >> n;

		for(int i=1; i<=n; ++i){
			cin >> x;
			graph[i][x] = 1;
		}

		for(int j=1; j<=n; ++j){
			if(!vis[j]){
				vis[j] = 1;
				DFS(j);
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
