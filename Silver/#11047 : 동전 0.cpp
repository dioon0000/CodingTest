//https://www.acmicpc.net/problem/11047
#include <bits/stdc++.h>
#define FOR(i, n) for(int i=0; i<n; ++i)
#define RFOR(i, n) for(int i=n; i>=0; --i)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, usedNum=0, tmp, idx;
    vector<int> val;

    cin >> n >> k;
    idx = n-1;

    FOR(i, n){
        cin >> tmp;
        val.push_back(tmp);
    }

    while(k>0){
        RFOR(i, idx){
            if(val[i] <= k){
                idx = i;
                usedNum += k/val[idx];
                k%=val[idx];
                break;
            }
        }

    }

    cout << usedNum << '\n';
    return 0;
}
