#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	vector<int> a(26, 100);
	int val=0;

	for(int i=0; i<keymap.size(); ++i){
		for(int j=0; j<keymap[i].length(); ++j){
			if(a[keymap[i][j]-'A'] > j)
				a[keymap[i][j]-'A'] = j+1;
		}
	}

	for(int i=0; i<a.size(); ++i)
		if(a[i] == 100)
			a[i] = -1;

	for(int i=0; i<targets.size(); ++i){
		val = 0;
		for(int j=0; j<targets[i].length(); ++j){
			if(a[targets[i][j]-'A'] != -1)
				val+=a[targets[i][j]-'A'];
			else{
				val = -1;
				break;
			}
		}
		answer.push_back(val);
	}
	return answer;
}