#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int from, int tmp, int to, vector<vector<int>>& answer) {
    vector<int> v;

    if(n==1) {
        // from -> to
        v.push_back(from);
        v.push_back(to);
        answer.push_back(v);
    }
    else {
        // N-1개를 from -> tmp
        hanoi(n-1, from, to, tmp, answer);

        //from에 있는 1개를
        //from -> to
        v.push_back(from);
        v.push_back(to);
        answer.push_back(v);

        // tmp의 N-1개 tmp -> to
        hanoi(n-1, tmp, from, to, answer);
    }

    return;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3, answer);

    return answer;
}