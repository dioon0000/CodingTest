#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> ans;
    int tmp = 0;
    for(int i=1; i<=n; ++i){
        tmp=x*i;
        ans.push_back(tmp);
    }
    return ans;
}