//BackTracking PS (중복 조합)
#include <iostream>
#define MAX 9
using namespace std;

int n,m;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void dfs(int num, int cnt){
  if(cnt == m){
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i = num; i <= n; i++){
    arr[cnt] = i;
    dfs(i,cnt+1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  dfs(1,0);
}
