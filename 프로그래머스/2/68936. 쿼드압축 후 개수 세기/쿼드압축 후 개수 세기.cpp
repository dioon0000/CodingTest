#include <iostream>
#include <string>
#include <vector>
using namespace std;

void section(int n, int r, int c, const vector<vector<int>>& arr, vector<int>& answer) {
    bool zero = false;
    bool one = false;

    // 모든 범위 탐색
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(arr[r+i][c+j] == 1)
                one = true;
            if(arr[r+i][c+j] == 0)
                zero = true;
        }
    }

    // 1. 모든 수가 1일 때
    if(one && !zero) {
        answer[1]++;
        return;
    }
    // 2. 모든 수가 0일 때
    if(zero && !one) {
        answer[0]++;
        return;
    }
    // 3. 0과 1이 뒤섞여 있을 때
    section(n/2, r, c, arr, answer);
    section(n/2, r + (n/2), c, arr, answer);
    section(n/2, r, c + (n/2), arr, answer);
    section(n/2, r + (n/2), c + (n/2), arr, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0); // 0 1 Cnt

    section(arr.size(), 0, 0, arr, answer);
    return answer;
}