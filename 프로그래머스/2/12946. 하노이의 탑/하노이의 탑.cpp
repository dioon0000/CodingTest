#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int go, int to, vector<vector<int>>& answer) {
    if (n == 1) {// 쌓인 원판이 한개라면 
        answer.push_back({go, to});
        return ;
    }
    hanoi(n-1, go, 6-go-to, answer);// n-1 개의 원판을 시작점, 목표점을 제외한 곳으로 이동
    hanoi(1, go, to, answer);// n번째 원판을 목표지점으로 이동
    hanoi(n-1, 6-go-to, to, answer);// n-1 개의 원판을 목표점으로 이동
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);

    return answer;
}