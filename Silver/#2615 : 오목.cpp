#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 19
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

bool Check(int arr[][MAX], int row, int col, int target){
  bool flag = false;

  //오른쪽 검사
  if(col <= 14){
    bool right_flag = false;
    for(int i=0; i<5; ++i)
      if(arr[row][col+i] != target)
        right_flag = true;
    
    if(col <= 13 && arr[row][col+5] == target && !right_flag)
      right_flag = true;
    if(col >= 1 && arr[row][col-1] == target && !right_flag)
      right_flag = true;

    if(!right_flag){
      cout << target << '\n' << row+1 << ' ' << col+1 << '\n';
      flag = true;
    }

    //오른쪽 대각선 아래 검사
    if(row <= 14){
      bool right_down_flag = false;
      for(int i=0; i<5; ++i)
        if(arr[row+i][col+i] != target)
          right_down_flag = true;
    
      if(col <= 13 && row <= 13 && arr[row+5][col+5] == target && !right_down_flag)
        right_down_flag = true;
      if(col >= 1 && row >= 1 && arr[row-1][col-1] == target && !right_down_flag)
        right_down_flag = true;

      if(!right_down_flag){
        cout << target << '\n' << row+1 << ' ' << col+1 << '\n';
        flag = true;
      }
    }
  }

  //아래 검사
  if(row <= 14){
    bool down_flag = false;
    for(int i=0; i<5; ++i)
      if(arr[row+i][col] != target)
        down_flag = true;
    
    if(row <= 13 && arr[row+5][col] == target && !down_flag)
      down_flag = true;
    if(row >= 1 && arr[row-1][col] == target && !down_flag)
      down_flag = true;

    if(!down_flag){
      cout << target << '\n' << row+1 << ' ' << col+1 << '\n';
      flag = true;
    }

    //왼쪽 대각선 아래 검사
    if(col >= 4){
      bool left_down_flag = false;
      for(int i=0; i<5; ++i)
        if(arr[row+i][col-i] != target)
          left_down_flag = true;

      if(row <= 13 && col >= 5 && arr[row+5][col-5] == target && !left_down_flag)
        left_down_flag = true;
      if(row >= 1 && col <= 18 && arr[row-1][col+1] == target && !left_down_flag)
        left_down_flag = true;
      
      if(!left_down_flag){
        vector<pair<int, int>> v;
        for(int i=0; i<5; ++i)
          v.push_back(make_pair(row+i, col-i));
        
        sort(v.begin(), v.end(), cmp);

        cout << target << '\n' << v[0].first+1 << ' ' << v[0].second+1 << '\n';
        flag = true;
      }
    }
  }

  return flag;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  bool flag = false;
  int omok[MAX][MAX];
  int x, y, t;

  //오목판 상태 INPUT
  for(int i=0; i<MAX; ++i){
    for(int j=0; j<MAX; ++j){
      cin >> omok[i][j];
    }
  }

  //piv 값을 잡아주기 위한 for문
  for(int i=0; i<MAX; ++i){
    for(int j=0; j<MAX; ++j){
      //Black
      if(omok[i][j] == 1){
        if(Check(omok, i, j, 1)){
          flag = true;
          goto EXIT;
        }
      }
      //White
      else if(omok[i][j] == 2){
        if(Check(omok, i, j, 2)){
          flag = true;
          goto EXIT;
        }
      }
    }
  }

  EXIT:
  if(!flag)
    cout << 0;

  return 0;
}