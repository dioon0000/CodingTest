#include <string>
#include <cctype>
#include <map>
using namespace std;

int solution(string s) {
    string ans = "";
    string tmp = "";
    map<string, int>m = {
        {"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}
    };
    
    for(int i=0; i<s.length(); ++i){
        if(isdigit(s[i]) != 0)
            ans+=s[i];
        else
            tmp+=s[i];
        if(m.find(tmp) != m.end()){
            ans+=to_string(m[tmp]);
            tmp = "";
        }
    }
    
    return stoi(ans);
}