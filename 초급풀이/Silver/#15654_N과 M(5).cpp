//https://www.acmicpc.net/problem/15654
#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] ={0, }, list[MAX] ={0, };
bool visited[MAX] ={0, };
void dfs(int cnt){
    //Base Condition
    if(cnt == m){
        for(int i=0; i<m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    //Recursion Func
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = list[i];
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> list[i];

    sort(list, list+n);
    dfs(0);
    return 0;
}
