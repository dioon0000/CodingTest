#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
using namespace std;

int n, h, w; //h는 행 w는 열
double expect_value = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visit[MAX][MAX] = {0,};
char maze[MAX][MAX];
queue<pair<int,int>> q;

void BFS(){

  while(q.size() != 0){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(nx>=0 && ny>=0 && nx<h && ny<w)
        if(visit[nx][ny] == false)
          if(maze[nx][ny] == '.' || maze[nx][ny] == 't'){
            expect_value++;
            visit[nx][ny] = true;
            q.push(make_pair(nx,ny));
          }
    }
  }
  cout << fixed;
  cout.precision(2);
  cout << expect_value << '\n';
  expect_value = 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
      cin >> h >> w;

      for(int j=0; j<h; j++)
        for(int k=0; k<w; k++){
          cin >> maze[j][k];
          if(maze[j][k] == 's'){
            q.push(make_pair(j,k));
            visit[j][k] = true;
          }
        }

        BFS();
        memset(visit, false, sizeof(visit));
    }
    return 0;
}