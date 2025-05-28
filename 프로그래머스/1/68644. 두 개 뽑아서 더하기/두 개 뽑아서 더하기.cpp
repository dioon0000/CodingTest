#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num) {
    vector<int> ans;
    
    for(int i=0; i<num.size()-1; ++i){
        for(int j=i+1; j<num.size(); ++j){
            if(ans.empty())
                ans.push_back(num[i]+num[j]);
            else{
                if(find(ans.begin(), ans.end(), num[i]+num[j]) == ans.end())
                    ans.push_back(num[i]+num[j]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}