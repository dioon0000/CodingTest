#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> proDay;
    for(int i=0; i<progresses.size(); ++i)
    {
        int remain = 100-progresses[i];
        if(remain%speeds[i]!=0)
            proDay.push(remain/speeds[i]+1);
        else
            proDay.push(remain/speeds[i]);
    }

    int cnt = 1;
    int preday = proDay.front();
    proDay.pop();

    while(!proDay.empty())
    {
        int curday = proDay.front();
        proDay.pop();
        if(preday>=curday)
        {
            cnt++;
        }
        else
        {
            answer.push_back(cnt);
            preday = curday;
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}