#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> tmp(3,0);
	vector<vector<int>> st = { {1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5} };
	for(int i=0; i<answers.size(); ++i){
		if(answers[i] == st[0][i%st[0].size()])	tmp[0]++;
		if(answers[i] == st[1][i%st[1].size()])	tmp[1]++;
		if(answers[i] == st[2][i%st[2].size()])	tmp[2]++;
	}
	//cout << max(tmp[0]>tmp[1] ? tmp[0] : tmp[1], tmp[2]) << '\n';

	for(int i=0; i<3; ++i)
		if(max(tmp[0]>tmp[1] ? tmp[0] : tmp[1], tmp[2]) == tmp[i])
			answer.push_back(i+1);

	/*for(int x : answer)
		cout << x << ' ';*/
	return answer;
}