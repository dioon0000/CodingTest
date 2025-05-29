#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> tmp;
    int minVal = score[0];
    int minIdx = 0;
    for (int i = 0; i < score.size(); ++i) {
        if (i < k) {
            tmp.push_back(score[i]);
            if (minVal > score[i]) {
                minVal = score[i];
                minIdx = i;
            }
            answer.push_back(minVal);
        }
        else {
            if (score[i] > minVal) {
                tmp.push_back(score[i]);
                tmp.erase(min_element(tmp.begin(), tmp.end()));
                minVal = *min_element(tmp.begin(), tmp.end());
                answer.push_back(minVal);
            }
            else
                answer.push_back(minVal);
        }
    }
    return answer;
}