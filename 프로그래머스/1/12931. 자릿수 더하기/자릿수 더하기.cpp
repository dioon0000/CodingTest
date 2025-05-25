#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0, tmp = n;
    if(tmp < 10)
        answer+=tmp;
    else{
        while(tmp>=10){
            answer+=tmp%10;
            tmp/=10;
        }
        answer+=tmp;
    }
    return answer;
}