#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(left; left<=right; ++left){
        int cnt=0;
        for(int i=1; i<=left; ++i){
            if(left%i==0)
                cnt++;
        }
        if(cnt%2==0)
            answer+=left;
        else
            answer-=left;
        
    }
    return answer;
}