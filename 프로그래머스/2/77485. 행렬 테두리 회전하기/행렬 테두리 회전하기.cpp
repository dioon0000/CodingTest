#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns));
    // 벡터에 값을 채워 넣음
    for(int i=1; i<=rows; ++i) {
        for(int j=1; j<=columns; ++j) {
            v[i-1][j-1] = (i-1)*columns+j;
        }
    }

    // 각 쿼리에 맞게 값을 로테이션 시킴 (실제 벡터 값을 회전)
    for(int i=0; i<queries.size(); ++i) {
        int x1 = queries[i][0]-1, y1 = queries[i][1]-1, x2 = queries[i][2]-1, y2 = queries[i][3]-1;
        int temp, minVal = 10001; // 회전 시 임시 값과 최소 값을 저장할 변수
        
        // 회전 로직
        temp = v[x1][y1];
        for(int j=x1; j<x2; ++j) {
            minVal = min(v[j][y1], minVal);
            v[j][y1] = v[j+1][y1];
        }
        for(int j=y1; j<y2; ++j) {
            minVal = min(v[x2][j], minVal);
            v[x2][j] = v[x2][j+1];
        }
        for(int j=x2; j>x1; --j) {
            minVal = min(v[j][y2], minVal);
            v[j][y2] = v[j-1][y2];
        }
        for(int j=y2; j>y1; --j) {
            minVal = min(v[x1][j], minVal);
            v[x1][j] = v[x1][j-1];
        }
        v[x1][y1+1] = temp;

        answer.push_back(minVal);
    }
    return answer;
}