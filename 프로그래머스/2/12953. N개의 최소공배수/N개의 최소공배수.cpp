#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) 
{
    int answer = 0, lcm = 0;
    sort(arr.begin(), arr.end(), greater());
    lcm = arr[0];

    while(1)
    {
        bool flag = false;
        for(auto idx : arr)
        {
            if(lcm%idx!=0)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            answer = lcm;
            break;
        }
        lcm+=arr[0];
    }
    return answer;
}