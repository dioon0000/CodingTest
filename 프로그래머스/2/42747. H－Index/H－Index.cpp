#include <vector>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    int min_h = citations.size()/2;

    for(int i = citations.size(); i>=min_h; --i)
    {
        int cnt = 0;
        for(int j = 0; j < citations.size(); ++j)
        {
            if(citations[j] >= i) cnt++;
        }
        if(cnt >= i)
        {
            answer = i;
            break;
        }
    }
    return answer;
}