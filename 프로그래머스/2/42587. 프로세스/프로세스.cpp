#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> p, int l)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for(int i=0; i<p.size(); ++i)
    {
        q.push({p[i], i});
        pq.push(p[i]);
    }
    while(!q.empty())
    {
        if(q.front().first == pq.top())
        {
            if(q.front().second == l)
            {
                answer++;
                break;
            }
            q.pop();
            pq.pop();
            answer++;
        }
        else
        {
            pair<int,int> temp;
            temp = q.front();
            q.pop(); q.push(temp);
        }
    }
    return answer;
}