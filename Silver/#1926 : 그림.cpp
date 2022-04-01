#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int paper[500][500];
bool vis[500][500];
const int dx[4] = {1,0,-1,0};
const int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, cnt=0, area=0, mx=0;
	queue<pair<int,int>> Q;

	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j) 
			cin >> paper[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (paper[i][j] == 1 && vis[i][j] == 0) {
				vis[i][j] = 1;
				Q.push({ i,j });
				cnt++;

				while (!Q.empty()) {
					area++;
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int k = 0; k < 4; ++k) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)	
							continue;
						if (vis[nx][ny] || paper[nx][ny] != 1)	
							continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
				mx = max(mx, area);
				area = 0;
			}
		}

	cout << cnt << '\n' << mx; 
	return 0;
}
