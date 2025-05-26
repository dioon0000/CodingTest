#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int tmp = 0;
    for(int i=0; i<absolutes.size(); ++i){
        if(signs[i] == true){
            answer+=absolutes[i];
        }
        else{
            tmp = absolutes[i]*-1;
            answer+=tmp;
        }
    }
    return answer;
}