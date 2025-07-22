#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    int len = number.length() - k;
    string answer = "";
    int StartIdx = 0;

    for(int i=0; i<len; ++i) {
        char MaxChar = number[StartIdx];
        int MaxIdx = StartIdx;

        for(int j=StartIdx+1; j<=k+i; ++j) {
            if(number[j] > MaxChar) {
                MaxChar = number[j];
                MaxIdx=j;

                if(MaxChar == '9') break;
            }

        }
        answer+=MaxChar;
        StartIdx = MaxIdx+1;
    }
    return answer;
}