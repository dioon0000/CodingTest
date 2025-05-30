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