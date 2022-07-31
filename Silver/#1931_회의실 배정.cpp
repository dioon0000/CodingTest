//https://www.acmicpc.net/problem/1931
//Task Scheduling Problem
#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int s, e, t=0;
vector<pair<int, int>> v;

bool compare(const pair<int, int> &a, const pair<int, int>& b){
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i=0; i<n; ++i){
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), compare); // O(NlogN)
    for(int i=0; i<n; ++i){
        if(v[i].first >= t){
            ans+=1;
            t = v[i].second;
        }
    }

    cout << ans << '\n';
    return 0;
}
