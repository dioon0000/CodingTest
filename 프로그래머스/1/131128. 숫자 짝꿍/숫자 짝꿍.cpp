#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> xArr(10, 0);
    vector<int> yArr(10, 0);
    vector<int> zArr(10, 0);
    int idx = 0, flag = false;
    for(int i=0; i<X.length(); ++i){
        idx = X[i]-'0';
        xArr[idx]++;
    }
    for(int i=0; i<Y.length(); ++i){
        idx = Y[i]-'0';
        yArr[idx]++;
    }
    for(int i=0; i<10; ++i){
        //cout << min(xArr[i],yArr[i]) << '\n';
        zArr[i] = min(xArr[i],yArr[i]);
    }
    for(int i=9; i>=0; --i){
        for(int j=0; j<zArr[i]; ++j){
            if(zArr[i]>0){
                if(i!=0)
                    flag = true;
                answer+=to_string(i);
            }
        }
    }
    if(answer=="")
        answer="-1";
    else if(!flag)
        answer="0";
    return answer;
}