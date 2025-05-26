#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n) {
    int ans=0;
    vector<int> v;
    while(n>0){
        v.push_back(n%3);
        n/=3;
    }
    
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); ++i){
        ans+=v[i]*pow(3,i);
    }
    return ans;
}