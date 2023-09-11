#include <iostream>
using namespace std;

int n, cnt=0;
int dx[3] = {0,1,1};
int dy[3] = {1,1,0};
int arr[17][17];

void dfs(int r, int c, int l){
  if(r==n && c==n){
    cnt++;
    return;
  }

  for(int i=0; i<3; ++i){
    int nx = dx[i]+r;
    int ny = dy[i]+c;
    
    if(i==0){
      if(arr[nx][ny]==1)
        continue;
      else if(nx>n || ny>n)
        continue;
      else if(l==2)
        continue;
      dfs(nx,ny,i);
    }
    if(i==1){
      if(arr[nx][ny]==1 || arr[nx-1][ny]==1 || arr[nx][ny-1]==1)
        continue;
      else if(nx>n || ny>n)
        continue;
      dfs(nx,ny,i);
    }
    if(i==2){
      if(arr[nx][ny]==1)
        continue;
      else if(nx>n || ny>n)
        continue;
      else if(l==0)
        continue;
      dfs(nx,ny,i);
    }
  }
  return;
}
int main(){
  cin >> n;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=n; ++j){
      cin >> arr[i][j];
    }
  }
  dfs(1, 2, 0);
  cout << cnt;
  return 0;
}