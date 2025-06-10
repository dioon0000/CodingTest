#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer(players);
	map<string, int> rank;
	map<string, int>::iterator iter;
	string temp;

	for(int i=0; i<players.size(); ++i)
		rank[players[i]] = i+1;

	for(int i=0; i<callings.size(); ++i){
		iter = rank.find(callings[i]);
		rank[iter->first]-=1;
		rank[answer[iter->second-1]]+=1;
		
		temp = iter->first;
		answer[iter->second] = answer[iter->second-1];
		answer[iter->second-1] = temp;
	}
	return answer;
}