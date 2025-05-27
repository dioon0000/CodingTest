#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int ans = 0;
    string comp = "";
    int tlen = t.size();
    int plen = p.size();
    for(int i=0; i<tlen-plen+1; ++i){
        comp = "";
        comp = t.substr(i,plen);
        if(p.compare(comp)>=0){
            ans++;
        }
    }
    return ans;
}