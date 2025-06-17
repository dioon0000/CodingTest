#include <vector>

using namespace std;

long long solution(int n) 
{
    long long answer = 0;
    vector<long long> v(n+1, 0);
    v[0] = 1; v[1] = 2;
    
    for(int i=2; i<=n; ++i) v[i]= (v[i-1]+v[i-2])%1234567;
    
    answer = v[n-1];
    return answer;
}