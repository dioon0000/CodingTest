//너비우선 탐색 구현
#include <iostream>
#include <cstring>
#include <queue>
#define MAX 101
using namespace std;

int n;
int dx[4] = {0 ,0 ,1 ,-1};
int dy[4] = {1 ,-1, 0, 0};
char area[MAX][MAX];
int visited[MAX][MAX] = {0,};

void BFS(int a, int b){
  //x, y좌표를 받을 queue 생성
  queue<pair<int, int>> q;
  q.push(make_pair(a, b));
  visited[a][b] = 1;

  //queue가 0이 아닐때까지 돌림
  while(q.empty() == 0){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    //사분면을 조사하기 위한 for문
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(nx>= 1 && ny>=1 && nx<=n && nx<=n)
        if(visited[nx][ny] == 0)
          if(area[nx][ny] == area[x][y]){
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
          }
    }
  }
}

void Solution(){
  int f_num=0, s_num=0;
  //0,0부터 너비우선탐색 (일반인)
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      if(visited[i][j] == 0){
        BFS(i, j);
        f_num++;
      }

  //visited 배열 초기화
  memset(visited, 0, sizeof(visited));

  //0,0부터 너비우선탐색 (적록색약자)
  for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            //G를 R로 바꿔줌
            if (area[i][j] == 'G') area[i][j] = 'R';

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (visited[i][j] == false){
                BFS(i, j);
                s_num++;
            }

  cout << f_num << " " << s_num;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      cin >> area[i][j];

  Solution();
  return 0;
}