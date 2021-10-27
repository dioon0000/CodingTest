#include <iostream>
#include <vector>
#define AREA_MAX 501
#define HEIGHT_MAX 257
using namespace std;

void BruteForce(vector<int> area[AREA_MAX], const int row, const int col, const int block){
  int minTime = 1000000000;
  int areaHeight;
  for(int i=0; i<HEIGHT_MAX; ++i){
    int inventory = block;
    int time = 0;
    for(int j=0; j<row; ++j)
      for(int k=0; k<col; ++k){
        if(area[j][k] > i){
          inventory += area[j][k] - i;
          time += 2*(area[j][k] - i);
        }
        else if(area[j][k] < i){
          inventory -= i - area[j][k];
          time += i - area[j][k];
        }
      }
    if(inventory >= 0)
      if(minTime >= time){
        minTime = time;
        areaHeight = i;
      }
  }

  cout << minTime << ' ' << areaHeight;
  return ;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m, b, tmp;
  vector<int> v[AREA_MAX];
  cin >> n >> m >> b;
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j){
      cin >> tmp;
      v[i].push_back(tmp);
    }

  BruteForce(v, n, m, b);
  return 0;
}

