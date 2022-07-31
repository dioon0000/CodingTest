//BruteForce 기본문제
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

char chess[MAX][MAX];
char white_chessboard[8][8] = {
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W'};
char black_chessboard[8][8] = {
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B',
  'B','W','B','W','B','W','B','W',
  'W','B','W','B','W','B','W','B'};

int WhiteChecker(const int x, const int y){
  int result = 0;
  for(int i=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      if(chess[x+i][y+j] != white_chessboard[i][j])
        result++;
    }
  }

  return result;
}

int BlackChecker(const int x, const int y){
  int result = 0;
  for(int i=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      if(chess[x+i][y+j] != black_chessboard[i][j])
        result++;
    }
  }

  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //n은 row, m은 col, change_min_value의 초기값은 8*8의 체스판의 색을 모두 바꾸는 경우이므로 64
  int n, m, change_min_value = 64; 
  cin >> n >> m;

  //chess input
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      cin >> chess[i][j];

  int first_black, first_white;
  //BruteForce Pos(x, y)
  for(int i=0; i<=n-8; ++i){
    for(int j=0; j<=m-8; ++j){
      first_black = BlackChecker(i, j);
      first_white = WhiteChecker(i, j);
      if(first_black < first_white){
        change_min_value = (first_black < change_min_value) ? first_black : change_min_value;
      }
      else{
        change_min_value = (first_white < change_min_value) ? first_white : change_min_value;
      }
    }
  }  
  cout << change_min_value;
  return 0;
}
