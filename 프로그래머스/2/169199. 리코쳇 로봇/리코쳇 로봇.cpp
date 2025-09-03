#include <bits/stdc++.h>
using namespace std;

// 상하좌우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int BFS(const vector<string>& board) {
    int row = board.size(), col = board[0].length(), cnt=0;
    int srow = 0, scol = 0, erow = 0, ecol = 0;
    vector<vector<bool>> visit(row, vector<bool>(col, false));
    queue<tuple<int, int, int>> q;

    // 시작과 끝의 좌표를 찾는 for문
    for(int i=0; i<row; ++i) {
        for(int j=0; j<col; ++j) {
            if(board[i][j] == 'R') { srow = i, scol = j; }
            if(board[i][j] == 'G') { erow = i, ecol = j; }
        }
    }

    q.push({ srow, scol, 0 });
    visit[srow][scol] = true;

    while(!q.empty()){
        auto [cy, cx, dist] = q.front(); q.pop();
        if(cy == erow && cx == ecol) return dist; // 도착 시 최단 거리 반환

        for(int i=0; i<4; ++i) {
            int ny = cy, nx = cx;

            while(1) {
                ny += dy[i]; nx += dx[i];
                if(ny<0 || nx<0 || ny>=row || nx>=col || board[ny][nx]=='D') {
                    ny -= dy[i]; nx -= dx[i];
                    if(!visit[ny][nx]) {
                        visit[ny][nx] = true;
                        q.push({ ny, nx, dist+1 });
                    }
                    break;
                }
            }
        }
    }
    return -1;
}
int solution(vector<string> board) {
    int answer = 0;

    answer = BFS(board);
    return answer;
}