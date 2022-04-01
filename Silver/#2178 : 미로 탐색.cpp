#include <bits/stdc++.h>
#define MAX 102
#define X first
#define Y second
using namespace std;

string maze[MAX];
int dist[MAX][MAX];
queue<pair<int, int>> q;
const int dx[4] ={1, 0, -1, 0};
const int dy[4] ={0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		fill(dist[i], dist[i]+m, -1);
		cin >> maze[i];
	}

	dist[0][0] = 0;
	q.push({0, 0});

	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if(nx<0 || nx>=n || ny<0 || ny>=m)	continue;
			if(dist[nx][ny]>=0 || maze[nx][ny]!='1')	continue;

			//dist[nx][ny]의 값을 현재 dist 상태에서 1칸을 증가시킴
			dist[nx][ny] = dist[cur.X][cur.Y]+1;
			q.push({nx, ny});
		}
	}

	cout << dist[n-1][m-1]+1;
	return 0;
}