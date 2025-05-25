#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int tmp;
    while(n>=10){
        tmp = n/10;
        answer.push_back(n%10);
        n = tmp;
    }
    answer.push_back(n);
    return answer;
}