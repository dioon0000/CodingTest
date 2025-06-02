#include <string>
#include <vector>

using namespace std;

int solution(vector<string> b) {
    int ans = 0;
    for(string str : b){
        bool flag[5] = { false, };
        for(int i=0; i<str.length(); ++i){
            if(str[i] == 'a' && str.substr(i, 3)=="aya" && !flag[0]){
                flag[0] = true;
                flag[1] = false;
                flag[2] = false;
                flag[3] = false;
                i+=2;
            }
            else if(str[i] == 'y' && str.substr(i, 2)=="ye" && !flag[1]){
                flag[1] = true;
                flag[0] = false;
                flag[2] = false;
                flag[3] = false;
                i+=1;
            }
            else if(str[i] == 'w' && str.substr(i, 3)=="woo" && !flag[2]){
                flag[2] = true;
                flag[0] = false;
                flag[1] = false;
                flag[3] = false;
                i+=2;
            }
            else if(str[i] == 'm' && str.substr(i, 2)=="ma" && !flag[3]){
                flag[3] = true;
                flag[0] = false;
                flag[1] = false;
                flag[2] = false;
                i+=1;
            }
            else{
                flag[4] = true;
            }
        }
        if(!flag[4])
            ans++;
    }
    return ans;
}