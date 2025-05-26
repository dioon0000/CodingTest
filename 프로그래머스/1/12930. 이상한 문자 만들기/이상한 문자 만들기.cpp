#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt=0;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == ' '){
            cnt = 0;
        }
        else{
            if(cnt%2==0){
                if(s[i]>='a'){
                    s[i] = s[i]-32;
                }
            }
            else{
                if(s[i]<='Z'){
                    s[i] = s[i]+32;
                }
            }
            cnt++;
        }
    }
    answer+=s;
    return answer;
}