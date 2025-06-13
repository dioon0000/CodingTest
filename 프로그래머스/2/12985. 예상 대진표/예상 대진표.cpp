#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    for(int i=0; i<n/2; ++i){
        answer++;
        if(a%2!=0 && b%2==0 && a+1==b)
            break;
        else if(a%2==0 && b%2!=0 && b+1==a)
            break;
        if(a%2==0) a/=2;
        else a=a/2+1;
        if(b%2==0) b/=2;
        else b=b/2+1;
    }

    return answer;
}