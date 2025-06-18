#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> e) 
{
    unordered_set<int> s;
    vector<int> v;
    int sum = 0, size = e.size(), len = 0, ans = 0;
    //벡터에 누적합을 저장하기 위한 이중 for문 size*i+j 위치에 push_back()
    for(int i=0; i<e.size(); ++i)
    {
        for(int j=0; j<e.size(); ++j)
        {
            int temp = 0;
            if(!len)
            {
                temp = e[(size*i)+j];
                v.push_back(temp);
            }
            else if(len < size-1)
            {
                temp = v[(size*(i-1))+j] + e[(j+len)%size];
                v.push_back(temp);
            }
            else
            {
                temp = v[(size*(i-1))+j] + e[i];
                v.push_back(temp);
                break;
            }
        }
        len++;
    }

    for(auto a : v)
        s.insert(a);

    ans = s.size();
    return ans;
}