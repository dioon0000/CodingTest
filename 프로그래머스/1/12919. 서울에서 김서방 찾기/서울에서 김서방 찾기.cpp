#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int cnt=0;
    string s_cnt;
    for(int i=0; i<seoul.size(); ++i){
        if(seoul[i] == "Kim")
            break;
        else    cnt++;
    }
    s_cnt = to_string(cnt);
    string answer = "김서방은 " +s_cnt + "에 있다";
    return answer;
}