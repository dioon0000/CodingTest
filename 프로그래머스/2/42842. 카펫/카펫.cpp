#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    double a=2, b=-brown+4, c=yellow*2, x=(-b+sqrt(b*b-4*a*c))/(2*a), y=(-b-sqrt(b*b-4*a*c))/(2*a);
    answer.push_back(x+2);
    answer.push_back(y+2);
    return answer;
}