#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;

int dy[4] = { 1, 0, 0, -1 };
int dx[4] = { 0, 1, -1, 0 };

vector<int> solution(vector<string> maps) {
	int n = maps.size(); int m = maps[0].size();
	vector<int> answer;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, int>> q;

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			// 바다가 아니고 방문한 지역이 아닐 경우
			if(maps[i][j] != 'X' && !visited[i][j]) {
				int sum = 0;
				q.push({ i, j });
				visited[i][j] = true;
				sum+=(maps[i][j]-'0');

				while(!q.empty()) {
					auto cur = q.front(); q.pop();

					for(int dir=0; dir<4; ++dir) {
						int ny = cur.X + dy[dir];
						int nx = cur.Y + dx[dir];

						if(ny<0 || ny >= n || nx<0 || nx>=m) continue;
						if(visited[ny][nx] || maps[ny][nx] == 'X') continue;

						q.push({ ny, nx });
						visited[ny][nx] = true;
						sum+=(maps[ny][nx]-'0');
					}
				}
				answer.push_back(sum);
			}
		}
	}

	if(answer.empty())
		answer.push_back(-1);
	else 
		sort(answer.begin(), answer.end(), less<int>());

	for(auto val : answer)
		cout << val << ' ';
	return answer;
}