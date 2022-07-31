//https://www.acmicpc.net/problem/11652
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
long long int arr[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 1, mxcnt = 0;
    long long int mxval = 0;
    for(int i=1; i<n; ++i){
        if(arr[i-1] == arr[i])
            cnt+=1;
        else
            cnt = 1;
        if(cnt > mxcnt){ 
            mxcnt = cnt;
            mxval = arr[i-1];
        }
    }

    if(n == 1)
        mxval = arr[0];

    cout << mxval;
    return 0;
}
