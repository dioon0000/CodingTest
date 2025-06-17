#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> t) 
{
    int ans = 0, sum = 0;
    map<int,int> m;
    vector<pair<int,int>> v;
    for(auto a : t) m[a]++;
    for(auto a : m) v.push_back(a);
    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); ++i)
    {
        sum+=v[i].second;
        ans++;
        if(sum >= k) break;
    }
    return ans;
}