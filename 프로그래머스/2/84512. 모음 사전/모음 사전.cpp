#include <string>
#include <vector>

using namespace std;

int answer = 0;
int cnt = -1;
string target = "";
string str = "AEIOU";
void dfs(string word) {
    // 종료 조건
    // word값과 dfs 단어 값이 같을 경우 종료
    // 문자열의 길이가 5보다 크거나 같을 경우 종료
    cnt++;

    if(target == word) {
        answer = cnt;
        return;
    }
    if(word.length() >= 5)
        return;

    for(int i=0; i<5; ++i)
        dfs(word+str[i]);
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}