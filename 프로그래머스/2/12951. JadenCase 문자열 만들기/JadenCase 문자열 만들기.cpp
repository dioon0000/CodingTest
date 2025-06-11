#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string str(s);

    while(str.find(" ")!= string::npos){
        int e_idx = str.find(" ");
        if(str[0] > '0' && str[0] < '9')
            for(int i=1; i<e_idx; ++i)
                str[i] = tolower(str[i]);
        else{
            str[0] = toupper(str[0]);
            for(int i=1; i<e_idx; ++i)
                str[i] = tolower(str[i]);
        }
        answer+=str.substr(0, e_idx+1);
        str = str.substr(e_idx+1);
    }

    if(str[0] > '0' && str[0] < '9')
        for(int i=1; i<str.length(); ++i)
            str[i] = tolower(str[i]);
    else{
        str[0] = toupper(str[0]);
        for(int i=1; i<str.length(); ++i)
            str[i] = tolower(str[i]);
    }
    answer+=str;
    return answer;
}