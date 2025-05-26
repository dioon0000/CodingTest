#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = (long long)num;
    bool flag = false;
    
    for(int i=1; i<=500; ++i){
        if(n==1)
            break;
        if(n%2==0){
            n/=2;
            answer++;
        }            
        else{
            n=(n*3)+1;
            answer++;
        }
        if(i==500 && n!=1){
            answer=-1;
        }
    }
    return answer;
}