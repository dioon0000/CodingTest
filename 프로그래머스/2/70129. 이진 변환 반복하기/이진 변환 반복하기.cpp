#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string binary(int len){
    string temp;
    while(len > 1){
        temp+=to_string(len%2);
        len/=2;
    }
    temp+=to_string(len);
    reverse(temp.begin(), temp.end());
    return temp;
}
vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0, len = 0, cnt = 0;
    while(s.length()>1){
        zero += count(s.begin(), s.end(), '0');
        len = s.length() - count(s.begin(), s.end(), '0');
        s = binary(len);
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}