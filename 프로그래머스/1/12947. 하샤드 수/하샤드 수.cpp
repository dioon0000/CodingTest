#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum=0, tmp=x;
    while(tmp){
        sum+=tmp%10;
        tmp/=10;
    }
    if(x%sum!=0)
        answer=false;
    return answer;
}