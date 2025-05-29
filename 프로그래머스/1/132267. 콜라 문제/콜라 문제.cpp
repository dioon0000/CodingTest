#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int ans = 0;
    int eb = n; //empty bottle

    while(eb >= a){
        ans+=(eb/a)*b;
        eb = (eb%a)+(eb/a)*b;
    }
    return ans;
}