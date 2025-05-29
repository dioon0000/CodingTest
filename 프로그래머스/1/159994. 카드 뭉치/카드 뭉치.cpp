#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1=0, idx2=0, idx=0;
    bool flag = false;
    while(idx < goal.size()){
        if(goal[idx] == cards1[idx1]){
            idx++;
            idx1++;
        }
        else if(goal[idx] == cards2[idx2]){
            idx++;
            idx2++;
        }
        else{
            flag = true;
            break;
        }
    }
    if(flag)
        answer+="No";
    else
        answer+="Yes";
    return answer;
}