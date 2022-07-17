//https://www.acmicpc.net/problem/2217
#include <bits/stdc++.h>
using namespace std;

int n, tmp, ans=0;
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for(int i=1; i<=n; ++i){
        ans = max(ans, v[n-i]*i);
    }

    cout << ans;
    return 0;
}
