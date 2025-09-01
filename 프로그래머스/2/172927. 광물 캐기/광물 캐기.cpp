#include <bits/stdc++.h>
using namespace std;

map<string, int> m; // "diamind" = 0, "iron" = 1, "stone" = 2
int fatigue[3][3] = { {1,1,1}, {5,1,1}, {25,5,1} }; // [곡괭이Index][해당광물피로도]

void DFS(vector<int>& picks, vector<string>& minerals, int& answer, int sum, int location) {

    // 광물을 다 캤거나 곡괭이들을 다 썼을때 피로도를 갱신
    if(location==minerals.size() || (picks[0]==0 && picks[1]==0 && picks[2]==0)) {
        answer=min(answer, sum);
        return;
    }
    // 모든 곡괭이 방문
    for(int i=0; i<3; i++) {

        // i 곡괭이가 있다면
        if(picks[i]!=0) {
            picks[i]--;

            int tmpIdx=location; // 곡괭이를 들면 5개를 연속으로 캐야함. 캐야할 광물의 임시 인덱스.
            int tmpSum=sum; // 광물을 캐며 누적된 임시 피로도
            for(tmpIdx; tmpIdx<location+5 && tmpIdx<minerals.size(); tmpIdx++) { // 5개를 캐거나 끝까지 캘때까지 
                tmpSum+=fatigue[i][m[minerals[tmpIdx]]]; // m[minerals[tmpIdx]] : tmpIdx 광물의 번호
            }

            DFS(picks, minerals, answer, tmpSum, tmpIdx);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = (25*50)+1; // 최고 피로도*최대광물개수

    // "diamind" = 0, "iron" = 1, "stone" = 2
    m.insert({ "diamond", 0 });
    m.insert({ "iron", 1 });
    m.insert({ "stone", 2 });

    DFS(picks, minerals, answer, 0, 0);
    return answer;
}