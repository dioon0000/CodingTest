#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    vector<bool> paint (n, false);
    int answer = 0;
    for(int i=0; i<section.size(); ++i){
        int idx = section[i]-1;
        if(paint[idx])
            continue;

        while(idx+m-1 >= n){
            idx--;
        }
        for(int i=idx; i<=idx+m-1; ++i){
            paint[i] = true;
        }
        answer++;
    }
    return answer;
}

/*
//더 나은 풀이
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;

    int pivot = section[0];
    //pivot+m은 pivot부터 m까지 색칠하는 부분보다 한칸 앞을 위치한다
    for(const auto v : section){
        if(v < pivot + m){
            continue;
        }
        else{
            pivot = v;
            answer++;
        }
    }

    return answer;
}
*/
