#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(long long n) {
    vector<int> v;
    long long answer = 0;
    
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<v.size(); ++i){
        answer*=10;
        answer+=v[i];
    }
    return answer;
}