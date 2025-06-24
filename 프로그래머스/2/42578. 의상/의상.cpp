#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    // 1. 옷을 종류별로 구분하기
    unordered_map<string, int> map;
    for (vector<string> clothe : clothes)
        map[clothe[1]]++;

    // for(auto a : map)
    //     cout << a.first << ' ' << a.second << ' ';

    // 2. 입지 않는 경우를 추가하여 모든 조합 계산하기
    int answer = 1;
    for (auto it = map.begin(); it != map.end(); it++)
        answer *= it->second + 1;

    // 3. 아무종류의 옷도 입지 않는 경우 제외하기
    return answer - 1;
}