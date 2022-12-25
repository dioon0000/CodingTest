#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100001]; //인접 정점을 저장할 vector 배열
int p[100001]; //부모 배열

//BFS Solved O(V+E), 트리에서 E는 V-1이므로 O(V)
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int nxt : adj[cur]){
			if(p[cur] == nxt) continue; //특정 노드에서 인접정점이 부모노드일 경우 continue
			q.push(nxt);
			p[nxt] = cur;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n-1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	BFS(1); //루트부터 순회

	for(int i=2; i<=n; ++i){
		cout << p[i] << '\n';
	}
	return 0;
}