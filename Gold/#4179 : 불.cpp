#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 1005
using namespace std;

int dx[4] ={1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};
char maze[MAX][MAX];
int fire[MAX][MAX];
int jihun[MAX][MAX];
queue<pair<int, int>> fq;
queue<pair<int, int>> jq;

int main(){
	//R은 미로 행의 개수, C는 열의 개수
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for(int i=0; i<r; ++i){
		fill(fire[i], fire[i]+c, -1);
		fill(jihun[i], jihun[i]+c, -1);
	}
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j){
			cin >> maze[i][j];
			if(maze[i][j] == 'F'){
				fire[i][j] = 0;
				fq.push({i, j});
			}
			if(maze[i][j] == 'J'){
				jihun[i][j] = 0;
				jq.push({i, j});
			}
		}
	//불 BFS
	while(!fq.empty()){
		auto cur = fq.front();
		fq.pop();

		for(int i=0; i<4; ++i){
			int nx = cur.X+dx[i];
			int ny = cur.Y+dy[i];

			if(nx<0 || nx>=r || ny<0 || ny>=c)
				continue;
			if(maze[nx][ny] == '#' || fire[nx][ny] >= 0)
				continue;

			fire[nx][ny] = fire[cur.X][cur.Y]+1;
			fq.push({nx, ny});
		}
	}
	//지훈 BFS
	while(!jq.empty()){
		auto cur = jq.front();
		jq.pop();

		for(int i=0; i<4; ++i){
			int nx = cur.X+dx[i];
			int ny = cur.Y+dy[i];

			if(nx<0 || nx>=r || ny<0 || ny>=c){
				cout << jihun[cur.X][cur.Y]+1;
				return 0;
			}

			if(maze[nx][ny] == '#' || jihun[nx][ny] >= 0)
				continue;
			if(fire[nx][ny] != -1 && jihun[cur.X][cur.Y]+1 >= fire[nx][ny])
				continue;

			jihun[nx][ny] = jihun[cur.X][cur.Y]+1;
			jq.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}