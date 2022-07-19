//https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>
#define MAX_LEN 100001
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, tmp, len = MAX_LEN, sum=0, en=0;
    vector<int> v;

    cin >> n >> s;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }

    sum = v[0];
    for(int st=0; st<n; ++st){ //O(N)
        while(en<n && sum<s){
            en++;
            if(en!=n)   sum+=v[en]; //en값이 범위를 벗어나지 않았을 경우에만 v[en]값을 sum 변수에 더해준다
        }
        if(en == n) break; //en값이 범위를 벗어났다면, st ~ en범위 사이에 s값 이상의 값이 존재하지 않는다는 뜻이므로 for문을 종료한다
        len = min(len, en-st+1);
        sum-=v[st];
    }

    if(len == MAX_LEN)
        cout << 0;
    else
        cout << len;
    return 0;
}
