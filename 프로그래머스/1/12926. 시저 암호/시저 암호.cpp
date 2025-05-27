#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); ++i){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(s[i]+n>'z'){
                s[i]=s[i]+n-('z'-'a'+1);
            }
            else
                s[i]=s[i]+n;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            if(s[i]+n>'Z'){
                s[i]=s[i]+n-('Z'-'A'+1);
            }
            else
                s[i]=s[i]+n;
        }
    }
    answer=s;
    return answer;
}