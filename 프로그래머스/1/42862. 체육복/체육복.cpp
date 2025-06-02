#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0, cnt = 0;
    vector<bool>isL(n+1, false);
    vector<bool>isR(n+1, false);

    for(int idx : lost)
        isL[idx] = true;
    for(int idx : reserve)
        isR[idx] = true;

    for(int i=1; i<=n; ++i)
        if(isL[i]){
            if(isR[i]){
                isL[i] = false;
                isR[i] = false;
            }
            else
                for(int j=i-1; j<=i+1; ++j)
                    if(j>=1 && j<=n && isR[j] && !isL[j]){
                        isL[i] = false;
                        isR[j] = false;
                        break;
                    }
        }

    for(int i=1; i<=n; ++i)
        if(isL[i])
            cnt++;

    answer = n-cnt;
    return answer;
}