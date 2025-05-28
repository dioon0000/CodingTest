#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string str = "";
    string answer = "";
    for(int i=1; i<food.size(); ++i){
        if(food[i]%2!=0)
            food[i]--;
        for(int j=0; j<food[i]/2; ++j){
            str+=to_string(i);
        }
    }
    answer+=str;
    answer+='0';
    reverse(str.begin(), str.end());
    answer+=str;
    return answer;
}