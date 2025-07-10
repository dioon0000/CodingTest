#include <iostream>
#include <queue>
using namespace std;

/*
자연수 x를 y로 변환하려고 합니다. 사용할 수 있는 연산은 다음과 같습니다.

x에 n을 더합니다
x에 2를 곱합니다.
x에 3을 곱합니다.
자연수 x, y, n이 매개변수로 주어질 때,
x를 y로 변환하기 위해 필요한 최소 연산 횟수를 return하도록
Solution 함수를 완성해주세요. 이때 x를 y로 만들 수 없다면 -1을 return 해주세요.
*/
vector<bool>visited(1000001, false);
queue<pair<int, int>> q;
int bfs(queue<pair<int,int>>& q, int y, int n) {
    while(!q.empty()){
        if(q.front().first == y)
            return q.front().second;
        
        int curVal = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        
        for(int i=0; i<3; ++i) {
            int newVal = 0;
            if(i==0)
                newVal=curVal+n;
            else if(i==1)
                newVal=curVal*2;
            else if(i==2)
                newVal=curVal*3;

            if(newVal<=y && !visited[newVal]) {
                visited[newVal] = true;
                q.push({ newVal, curCnt+1 });
            }
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    visited[x] = true;
    q.push({ x, 0 });
    answer = bfs(q,y,n);

    cout << answer;
    return answer;
}

int main() {
    solution(10, 40, 5);
    return 0;
}