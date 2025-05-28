#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<bool> isAlp(26, false);
    vector<int> preidx(26, -1);

    for(int i=0; i<s.length(); ++i){
        int idx = s[i]-'a';
        //아직 나오지 않은 수라면
        if(isAlp[idx] == false){
            answer.push_back(-1);
            preidx[idx] = i;
            isAlp[idx] = true;
        }
        //나온 수라면 현재 idx에서 이전 idx값을 빼준다
        else{
            answer.push_back(i-preidx[idx]);
            preidx[idx] = i;
        }

    }
    return answer;
}