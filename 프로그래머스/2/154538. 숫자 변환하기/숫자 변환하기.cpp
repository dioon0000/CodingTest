#include <queue>
using namespace std;

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

    return answer;
}