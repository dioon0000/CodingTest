#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#define MAX 26
#define X first
#define Y second
using namespace std;

char graph[MAX][MAX];
int vis[MAX-1][MAX-1];
int dx[4] ={1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};
int n, cnt=0;
priority_queue<int, vector<int>, greater<int>> pq;
stack<pair<int, int>> s;

void DFS(){
	int num = 1;
	while(!s.empty()){
		auto cur = s.top();	s.pop();
		for(int i=0; i<4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if(nx<0 || nx>=n || ny<0 || ny>=n)	continue;
			if(vis[nx][ny] || graph[nx][ny] == '0')	continue;

			num++;
			vis[nx][ny] = 1;
			s.push({nx, ny});
		}
	}

	pq.push(num);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	memset(vis, 0, sizeof(vis));

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> graph[i][j];

	//DFS 정점 찾기
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(graph[i][j] == '1' && !vis[i][j]){
				vis[i][j] = 1;
				s.push({i, j});
				cnt++;
				DFS();
			}
		}

	}

	cout << cnt << '\n';
	while(!pq.empty()){
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}
