//https://www.acmicpc.net/problem/2230
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, tmp, mn = INT_MAX, st=0, en=0;
    vector<int> v;
    
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end()); // O(NlogN)

    for(st; st<n; ++st){ //O(2N)
        for(en; en<n; ++en){
            if(v[en]-v[st] >= m){
                mn = min(mn, v[en]-v[st]);
                break;
            }
        }
    }

    cout << mn;
    return 0;
}
