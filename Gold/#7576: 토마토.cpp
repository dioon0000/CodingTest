#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

//전역변수는 초기화를 해주지않으면 자동으로 0을 삽입
int graph[1005][1005];
int day[1005][1005];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n; //m은 가로(열), n은 세로(행) 6, 4
	bool flag = false, one_flag = false;
	cin >> m >> n;
	for(int i=0; i<n; ++i){
		fill(day[i], day[i]+m, -1);

		for(int j=0; j<m; ++j){
			cin >> graph[i][j];
			if(graph[i][j] == 1){
				one_flag = true;
				day[i][j] = 0;
				q.push({i, j});
			}
			if(graph[i][j] == 0)
				flag = true;
		}
	}
	//익은 토마토만 있는 경우
	if(!flag && one_flag)
		cout << 0;

	//덜익은 토마토만 존재하는 경우
	else if(flag && !one_flag)
		cout << -1;

	//익은 토마토와 덜익은 토마토 모두있는 경우
	else if(flag && one_flag){
		while(!q.empty()){
			pair<int, int> cur = q.front();	q.pop();
			graph[cur.X][cur.Y] = 1;
			for(int i=0; i<4; ++i){
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if(nx<0 || nx>n || ny<0 || ny>m)
					continue;
				if(day[nx][ny] >= 0 || graph[nx][ny] == -1)
					continue;

				day[nx][ny] = day[cur.X][cur.Y]+1;
				q.push({nx, ny});
			}
		}
		bool status_flag = false; //BFS과정이후 덜익은 토마토가 존재한다면 flag값을 true로 변경

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(graph[i][j] == 0){
					status_flag = true;
					break;
				}

		if(status_flag)
			cout << -1;

		if(!status_flag){
			int mx = 0;
			for(int i=0; i<n; ++i){
				for(int j=0; j<m; ++j){
					if(day[i][j] > mx)
						mx = day[i][j];
				}
			}
			cout << mx;
		}
	}
	
	return 0;
}