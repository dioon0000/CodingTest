//https://www.acmicpc.net/problem/11536
#include <bits/stdc++.h>
#define MAX 25
using namespace std;

bool compare(const string& a, const string& b){
    return a>b;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string arr[MAX];
    string compare_arr[MAX];

    cin >> n;
    for(int i=0; i<n; ++i)  cin >> arr[i];
    for(int i=0; i<n; ++i)  compare_arr[i] = arr[i];
    sort(arr, arr+n, compare); //DECREASING

    bool flag = false;
    for(int i=0; i<n; ++i){
        if(arr[i] != compare_arr[i]){
            flag=true;
            break;
        }
    }

    if(!flag){
        cout << "DECREASING";
    }
    else{
        sort(arr, arr+n); //INCREASING
        flag = false;

        for(int i=0; i<n; ++i){
            if(arr[i] != compare_arr[i]){
                flag=true;
                break;
            }
        }

        if(!flag)
            cout << "INCREASING";
        else
            cout << "NEITHER";
    }
    return 0;
}
