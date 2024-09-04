//https://www.acmicpc.net/problem/2630
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std; 

int n, paper[128][128], white=0, blue=0;
//white = 0, blue = 1
void Division(int row, int col, int size){
    bool white_flag = false, blue_flag = false;

    //분할된 범위 탐색
    for(int i=row; i<row+size; ++i){
        for(int j=col; j<col+size; ++j){
            if(paper[i][j] == 0)
                white_flag = true;
            if(paper[i][j] == 1)
                blue_flag = true;
        }
    }
    //분할된 범위의 색이 섞여 있을경우
    if(white_flag && blue_flag){
        Division(row, col , size/2);
        Division(row, col+(size/2), size/2); 
        Division(row+(size/2), col, size/2);
        Division(row+(size/2), col+(size/2), size/2);
        return;
    }
    //분할된 범위의 색이 모두 하얀색일때
    if(white_flag && !blue_flag){
        white+=1;
        return;
    }
    //분할된 범위의 색이 모두 파란색일때
    else if(!white_flag && blue_flag){
        blue+=1;
        return;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cin >> paper[i][j];
    }

    Division(0, 0, n);
    cout << white << '\n' << blue;
    return 0;
}
