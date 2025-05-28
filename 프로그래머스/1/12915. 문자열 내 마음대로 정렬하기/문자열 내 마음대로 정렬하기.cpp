#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool compare(string s1, string s2){
    return s1[N] == s2[N] ? s1<s2 : s1[N] < s2[N];
}

vector<string> solution(vector<string> str, int n) {
    vector<string> ans;
    N = n;
    sort(str.begin(), str.end(), compare);
    for(string s : str)
        ans.push_back(s);
    return ans;
}