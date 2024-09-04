#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str, bomb, answer = "";
    cin >> str >> bomb;
    //bombIdx는 bomb의 마지막 문자열을 나타내는 인덱스
    int bombIdx = bomb.length()-1;

    //문자열의 길이만큼 검사하기 위한 for문
    for (int i = 0; i < str.length(); i++) {
        //한 문자 씩 넣어줌
        answer += str[i];
        //만약 문자열의 마지막 문자와 폭발 문자열의 마지막 문자가 같으면
        if (answer[answer.length()-1] == bomb[bombIdx]) {
            //만약 문자열의 길이가 폭발 문자열의 길이보다 크거나 같다면
            if (answer.length() >= bomb.length()) {
                //cnt값을 하나 올려준다 cnt값은 문자열을 검사했을 때 폭발 문자열이랑 동일한 길이인지 확인하기 위한 변수
                int cnt = 1;
                //폭발 문자열의 마지막부터 시작점까지 돌리는 for문
                for (int j = bombIdx - 1; j >= 0; j--) {
                    //문자열과 폭발 문자열이 동일한 부분에서 -1부분에서 시작하여 1씩 내려가면서 동일하지 않을 시 braek
                    if (answer[answer.length()-1 - (bombIdx - j)] != bomb[j])
                        break;
                    cnt++;
                }
                if (cnt == bomb.length()) 
                    for (int b = 0; b < bomb.length(); b++) 
                        answer.pop_back();
            }
        }
    }
    if (answer.empty())
        cout << "FRULA" << '\n';
    else
    cout << answer << '\n';

    return 0;
}
