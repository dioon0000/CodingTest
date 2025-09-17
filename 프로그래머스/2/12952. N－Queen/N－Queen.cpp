#include <vector>
#include <iostream>

using namespace std;

vector<int> board(12,0);
int answer = 0;

bool IsValid(int row) {
    for(int i=0; i<row; ++i) {
        if(board[row] == board[i] || abs(board[row]-board[i]) == row-i)
            return false;
    }

    return true;
}

void DFS(int n, int row) {
    // base condition
    if(row == n) {
        answer++;
        return;
    }

    for(int i=0; i<n; ++i) {
        board[row] = i;

        if(IsValid(row)) {
            DFS(n, row+1);
        }
    }
}

int solution(int n) {
    DFS(n, 0);
    return answer;
}