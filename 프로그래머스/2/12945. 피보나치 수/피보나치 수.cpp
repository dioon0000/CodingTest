#include <vector>

using namespace std;
int solution(int n) {
    vector<int> v(n+1,-1);
    v[0] = 0, v[1] = 1;
    int div = 1234567;
    int answer = 0;
    //미리 div값을 나누면서 더함
    for(int i=2; i<=n; ++i){
        v[i] = (v[i-1]%div) + (v[i-2]%div);
        v[i]%=div;
    }
    answer = v[n];
    return answer;
}

int main() { 
    solution(5);
    return 0;  
}