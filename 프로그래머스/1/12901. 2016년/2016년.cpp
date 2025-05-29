#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> day = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    string answer = "";
    int x = a-1, y = b-1 , d = 0;
    
    for (int i = 1; i <= x; ++i) 
        d += month[i - 1];
    
    d += y;
    answer += day[d%7];
    return answer;
}