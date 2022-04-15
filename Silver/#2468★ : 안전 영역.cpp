#include <bits/stdc++.h>
#define MAX 100
#define X first
#define Y second
using namespace std;

int dx[4] ={1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};
int gnd[MAX][MAX];
int tmp[MAX][MAX];
int vis[MAX][MAX];
stack<pair<int, int>> s;
priority_queue<int> pq;
int n, cnt = 0, mx = 0;

void DFS(){
	while(!s.empty()){
		auto cur = s.top();	s.pop();
		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if(nx<0 || nx>=n || ny<0 || ny>=n)	continue;
				if(tmp[nx][ny] == 0 || vis[nx][ny])	continue;

				s.push({nx, ny});
				vis[nx][ny] = 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j){
			cin >> gnd[i][j];
      //땅의 높이 중 가장 높은곳을 조사하여 mx에 초기화. 그 높이 이상의 강수량이라면 안전 영역은 확실하게 0이기 때문에 높이는 0<=h<=mx까지만 조사한다.
			if(gnd[i][j] > mx)
				mx = gnd[i][j];
		}

  //비가 아예 안오는 경우가 존재하므로 0부터 땅의 최대 높이 mx까지 안전영역 조사
	for(int h=0; h<=mx; ++h){
		copy(&gnd[0][0], &gnd[0][0]+MAX*MAX, &tmp[0][0]); //copy(복사 할 배열의 시작 주소값, 복사 할 배열의 마지막 주소값, 복사받을 배열의 시작 주소값)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(tmp[i][j] <= h)	tmp[i][j] = 0;

		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(tmp[i][j] != 0 && !vis[i][j]){
					cnt++;
					s.push({i, j});
					vis[i][j] = 1;
					DFS();
				}
		pq.push(cnt);
		cnt = 0;
		for(int k=0; k<n; ++k)
			fill(vis[k], vis[k]+n, 0);
	}

	cout << pq.top();
	
	return 0;
}