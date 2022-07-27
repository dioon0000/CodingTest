//https://www.acmicpc.net/problem/7569
#include <iostream>
#include <algorithm>
#include <tuple>
// #include <utility> pair를 지원하는 헤더, 단 algorithm과 vector 헤더파일에서 이미 include이므로 사용하지않아도 된다
#include <queue>
#include <vector>
#define Z get<0>(cur)
#define Y get<1>(cur)
#define X get<2>(cur)
using namespace std;

int box[105][105][105];
int day[105][105][105];
queue<tuple<int, int, int>> q;
//아래 위 오른쪽 왼쪽 면(위) 면(아래)
int dx[6] ={0, 0, 1, -1, 0, 0};
int dy[6] ={1, -1, 0, 0, 0, 0};
int dz[6] ={0, 0, 0, 0, 1, -1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h;
	bool zero_flag = false, one_flag = false;
	cin >> m >> n >> h;
	fill(&day[0][0][0], &day[101][100][100], -1);

	//3차원 배열의 입력을 받는 for문 (0은 익지않은 토마토, 1은 익은 토마토, -1은 토마토가 들어있지 않은 칸)
	for(int i=0; i<h; ++i)
		for(int j=0; j<n; ++j)
			for(int k=0; k<m; ++k){
				cin >> box[i][j][k];
				if(box[i][j][k] == 1){
					one_flag = true;
					day[i][j][k] = 0;
					q.push({i, j, k});
				}
				else if(box[i][j][k] == 0)
					zero_flag = true;
			}
  
	if(one_flag && !zero_flag)
		cout << 0;
	else if(!one_flag && zero_flag)
		cout << -1;
	//익은 토마토와 덜익은 토마토가 들어있는 박스일경우 BFS 탐색
	else{
		while(!q.empty()){
			tuple<int, int, int> cur = q.front();	q.pop();

			for(int i=0; i<6; ++i){
				int nz = Z+dz[i];
				int ny = Y+dy[i];
				int nx = X+dx[i];

				//좌표의 범위를 벗어나는 경우 continue;
				if(nx<0 || nx>=m || ny<0 || ny>=n || nz<0 || nz>=h)
					continue;
				//좌표의 값이 -1이거나 Day값이 -1이 아닌경우 continue;
				if(box[nz][ny][nx]==-1 || day[nz][ny][nx]>=0)
					continue;

				day[nz][ny][nx] = day[Z][Y][X]+1;
				box[nz][ny][nx] = 1;
				q.push({ nz, ny, nx });
			}
		}
		bool status_flag = false;

		for(int i=0; i<h; ++i)
			for(int j=0; j<n; ++j)
				for(int k=0; k<m; ++k)
					if(box[i][j][k] == 0){
						status_flag = true;
						break;
					}
    
		//익지않은 토마토가 존재 시
		if(status_flag)
			cout << -1;
		//익지않은 토마토가 존재하지 않을 시
		if(!status_flag){
			int mx = 0;
			for(int i=0; i<h; ++i)
				for(int j=0; j<n; ++j)
					for(int k=0; k<m; ++k)
						if(day[i][j][k] > mx)
							mx = day[i][j][k];
			cout << mx;
		}
	}

	return 0;
}
