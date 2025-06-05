#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	vector<bool> alpha(26, false);
	string answer = "";
	for(char a : skip)
		alpha[a-97] = true;

	for(int i=0; i<s.length(); ++i){
		for(int j=0; j<index; ++j){
			int idx = (s[i]+1)-97;
			if(idx == 26) idx = 0;
			while(alpha[idx]){
				idx++;
				if(idx == 26)
					idx = 0;
			}
			s[i] = idx+97;
		}
	}

	answer+=s;
	return answer;
}