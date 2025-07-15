#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
    string ab = a+b;
    string ba = b+a;
    
    if(ab > ba)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tnumbers;
    for(int x : numbers)
        tnumbers.push_back(to_string(x));

    sort(tnumbers.begin(), tnumbers.end(), comp);

    for(string str : tnumbers)
        answer+=str;

    if(answer[0] == '0')
        answer = "0";

    return answer;
}