#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> answer;
    vector<vector<int>> arr(1000, vector<int>(1000, 0));
    int state = 0, num = 1;
    int x = 0, y = 0;
    
    // 삼각 달팽이 로직은 무조건 n회 실행된다
    for(int i=0; i<n; ++i)
    {
        // 아래
        if(state == 0)
        {
            for(int j=i; j<n; ++j)
            {
                arr[x++][y] = num++;
            }
            x--; y++;
            state = 1;
        }
        // 오른쪽
        else if(state == 1)
        {
            for(int j=i; j<n; ++j)
            {
                arr[x][y++] = num++;
            }
            x--; y-=2;
            state = 2;
        }
        // 대각선 왼쪽 위
        else if(state == 2)
        {
            for(int j=i; j<n; ++j)
            {
                arr[x--][y--] = num++;
            }
            x+=2; y++;
            state = 0;
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}