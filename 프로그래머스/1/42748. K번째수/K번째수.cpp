#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    //command[][0] = i, command[][1] = j, command[][2] = k
    //command에 따라 잘려질 문자열 보관 command가 끝나면 초기화 해줘야함
    vector<int> tmp;
    //tmp 과정이 끝나면 저장할 벡터
    vector<int> answer;
    
    for(int i=0; i<commands.size(); ++i){
        int k = 0;
        for(int j=commands[i][0]-1; j<commands[i][1]; ++j){
            //cout << j << ' ';
            k = commands[i][2];
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k-1]);
        tmp.clear();
    }
    return answer;
}