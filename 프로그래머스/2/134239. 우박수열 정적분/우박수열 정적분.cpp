#include <iostream>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> collatz;

    collatz.push_back(k);
    // 콜라츠 추측 시행
    while(k!=1) {
        if(k%2==0)
            k/=2;
        else if(k%2!=0) 
            k=k*3+1;

        collatz.push_back(k);
    }

    // 정적분을 구하는 구간들의 목록
    for(int i=0; i<ranges.size(); ++i) {
        int start = ranges[i][0];
        int end = collatz.size() - 1 + ranges[i][1];
        double area = 0;
        // 시작점이 끝점보다 크다면 올바르지 않은 구간
        if(start > end) {
            answer.push_back(-1); 
            continue;
        }

        // 시작점에서 끝점까지의 구간 정적분
        for(int j=start; j<end; ++j) {
            area += (double)(collatz[j]+collatz[j+1]) / 2;
        }

        answer.push_back(area);
    }
    return answer;
}