#include <string>
#include <vector>

using namespace std;

int divide(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return divide(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd, lcm;
    
    if(n>m)
        gcd = divide(n,m);
    else
        gcd = divide(m,n);
    lcm = n*m/gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    return answer;
}