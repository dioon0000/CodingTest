#include <vector>  
#include <string>  
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer; //id_list의 순서대로 저장
    unordered_map<string, int> reported; //각 id가 신고받은 횟수를 저장 (정렬 필요없음)
    unordered_map<string, int> mail; //mail이 날아온 횟수를 저장
    unordered_map<string, unordered_set<string>> report_user; //신고자가 신고한 유저를 저장

    for(string s : id_list){
        reported[s] = 0;
        mail[s] = 0;
    }
    for(int i=0; i<report.size(); ++i){
        stringstream ss(report[i]);
        string from, to;
        ss >> from >> to;
        auto iter = report_user[from].insert(to);
        if(iter.second)
            reported[to]++;
    }
    /*for(auto a : reported)
        cout << a.first << ": " << a.second << '\n';*/

    for(const auto& i : report_user) {
        //cout << "신고자: " << i.first << " -> 신고한 유저: ";
        for(const auto& j : i.second) {
            //cout << j << ' ';
            if(reported[j] >= k){
                mail[i.first]++;
            }
        }
        //cout << '\n';
    }

    for(string s : id_list){
        answer.push_back(mail[s]);
        //cout << a.first << ": " << a.second << '\n';
    }
    return answer;
}