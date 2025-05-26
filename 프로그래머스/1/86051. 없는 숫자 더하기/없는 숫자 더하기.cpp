#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    int sum=0;
    for(int i=0; i<numbers.size(); ++i)
        sum+=numbers[i];
    answer-=sum;
    return answer;
}