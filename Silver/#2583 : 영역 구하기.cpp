#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define MAX 100
#define X first
#define Y second
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
stack<pair<int, int>> s;
int graph[MAX][MAX];
int vis[MAX][MAX];
int m, n, k, cnt = 0;
int dx[4] ={1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};

void DFS(){
	int area = 1;
	while(!s.empty()){
		auto cur = s.top();	s.pop();

		for(int i=0; i<4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if(nx<0 || nx>=m || ny<0 || ny>=n)	continue;
			if(!graph[nx][ny] || vis[nx][ny])	continue;

			area++;
			vis[nx][ny] = 1;
			s.push({nx, ny});
		}
	}
	pq.push(area);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	for(int i=0; i<m; ++i)
		fill(graph[i], graph[i]+n, 1);

	//k가지 직사각형
	for(int i=0; i<k; ++i){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int dx = x2-x1, dy = y2-y1;
    
		//직사각형 위치 전부 0으로 변경
		for(int j=0; j<dy; ++j){
			for(int k=0; k<dx; ++k){
				if(!graph[y1+j][x1+k])	continue;
				graph[y1+j][x1+k] = 0;
			}
		}
	}
	
	//DFS
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j)
			if(graph[i][j] && !vis[i][j]){
				cnt++;
				vis[i][j] = 1;
				s.push({i, j});
				DFS();
			}
	}

	cout << cnt << '\n';
	while(!pq.empty()){
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << '\n';

	return 0;
}