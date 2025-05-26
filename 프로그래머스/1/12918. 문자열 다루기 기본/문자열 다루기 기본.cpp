#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length()==4 || s.length()==6){
        for(int i=0; i<s.length(); ++i){
            if(65<=(int)s[i]&&(int)s[i]<=90){
            answer = false;
            break;
            }
            else if(97<=(int)s[i]&&(int)s[i]<=122){
            answer = false;
            break;
            }
        }
    }
    else{
        answer=false;
    }
    
    return answer;
}