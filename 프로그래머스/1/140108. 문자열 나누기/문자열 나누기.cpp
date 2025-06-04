#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, idx=0, e_idx=0, x=0, y=0;
	char cmp = NULL; //비교값
	for(int i=0; i<s.length(); ++i){
		e_idx = i;
		if(idx == e_idx) cmp = s[idx];

		if(s[i] == cmp)	x++;
		else y++;

		if(x==y){
			idx=e_idx+1;
			answer++;
			x=0;
			y=0;
		}
	}
	if(idx != e_idx+1) answer++;
    return answer;
}