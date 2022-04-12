#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 50
#define X first
#define Y second
using namespace std;

int dx[] ={1, 1, 0, -1, -1, -1, 0, 1};
int dy[] ={0, 1, 1, 1, 0, -1, -1, -1};
stack<pair<int, int>> s;
int graph[MAX][MAX];
int vis[MAX][MAX];
int w, h, il; //w=열, h=행

void DFS(){
	while(!s.empty()){
		auto cur = s.top();	s.pop();
		for(int i=0; i<8; ++i){
			int nx = cur.X + dx[i]; // h
			int ny = cur.Y + dy[i]; // w

			if(nx<0 || nx>=h || ny<0 || ny>=w)	continue;
			if(!graph[nx][ny] || vis[nx][ny])	continue;

			vis[nx][ny] = 1;
			s.push({nx, ny});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(1){
		il = 0;
		cin >> w >> h;
		if(!w && !h)
			break;
		
		for(int i=0; i<h; ++i){
			fill(vis[i], vis[i]+w, 0);
			fill(graph[i], graph[i]+w, 0);
		}

		for(int i=0; i<h; ++i)
			for(int j=0; j<w; ++j)
				cin >> graph[i][j];

		for(int i=0; i<h; ++i)
			for(int j=0; j<w; ++j)
				if(graph[i][j] && !vis[i][j]){
					s.push({i, j});
					vis[i][j] = 1;
					il++;
					DFS();
				}
		cout << il << '\n';
	}
	return 0;
}