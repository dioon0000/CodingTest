#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int temp = 0;

    answer.push_back(n);
    while(n != 1){
        if(n%2==0) {
            temp = n/=2;
            answer.push_back(temp);
            n = temp;
        }
        else {
            temp = 3*n+1;
            answer.push_back(temp);
            n = temp;
        }
    }
    return answer;
}