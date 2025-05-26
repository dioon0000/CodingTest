using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long cost = 0;
    for(int i=1; i<=count; ++i){
        cost+=price*i;
    }
    if(cost>money)
        answer = cost-money;
    else
        answer = 0;
    return answer;
}