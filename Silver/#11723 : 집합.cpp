//https://www.acmicpc.net/problem/11723
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, num, bit=0;
    string str;

    cin >> m;
    while(m--){
        cin >> str;
        if(str == "add"){
            cin >> num;
            bit |= 1<<num;
        }
        else if(str == "remove"){
            cin >> num;
            bit &= ~(1<<num);
        }
        else if(str == "check"){
            cin >> num;
            if(bit & 1<<num)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(str == "toggle"){
            cin >> num;
            bit ^= 1<<num;
        }
        else if(str == "all"){
            bit = (1<<21)-1;
        }
        else if(str == "empty"){
            bit = 0;
        }
    }
    return 0;
}
