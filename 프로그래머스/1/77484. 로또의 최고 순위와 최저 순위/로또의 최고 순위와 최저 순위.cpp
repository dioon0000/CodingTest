#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> l, vector<int> w) {
    vector<int> ans;
    int cnt = 0, z_cnt=0, min_rank=0, max_rank=0, tmp=0;
    for(int i=0; i<6; ++i){
        if(l[i] == 0)
            z_cnt++;

        vector<int>::iterator iter = find(l.begin(), l.end(), w[i]);

        if(iter!=l.end())
            cnt++;
    }

    //cout << z_cnt << ' ' << cnt << '\n';

    max_rank = 7-cnt-z_cnt;
    if(max_rank == 7)
        max_rank = 6;
    if(cnt == 0)
        min_rank = 6;
    else
        min_rank = 7-cnt;

    //cout << max_rank << ' ' << min_rank << '\n';
    ans.push_back(max_rank);
    ans.push_back(min_rank);
    return ans;
}