#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(const vector<string>& maps, queue<pair<int,int>> q, int n, int m, char tar) {
	vector<vector<int>> vis (n,vector<int>(m,-1));
	vis[q.front().Y][q.front().X] = 0;
	
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		
		for(int dir = 0; dir<4; ++dir) {
			int ny = cur.Y + dy[dir], nx = cur.X + dx[dir];

			if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if(vis[ny][nx]!=-1 || maps[ny][nx] == 'X') continue;

			if(maps[ny][nx] == tar) return vis[cur.Y][cur.X]+1;
			vis[ny][nx] = vis[cur.Y][cur.X] + 1;
			q.push({ ny,nx });
		}
	}

	return -1;
}
int solution(vector<string> maps) {
	int answer = 0, cnt = 0, n = maps.size(), m = maps[0].length();
	queue<pair<int, int>> firstQ;
	queue<pair<int, int>> secondQ;

	// Find
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(maps[i][j] == 'S') firstQ.push({ i,j });
			if(maps[i][j] == 'L') secondQ.push({ i,j });
		}
	}

	// First BFS
	cnt = bfs(maps, firstQ, n, m, 'L');
	if(cnt == -1) return -1;
	answer+=cnt;
	// Second BFS
	cnt = bfs(maps, secondQ, n, m, 'E');
	if(cnt == -1) return -1;
	answer+=cnt;
	return answer;
}