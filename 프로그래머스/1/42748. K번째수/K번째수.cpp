#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> temp;
    
	for(int i=0; i<commands.size(); ++i) {
		for(int j=commands[i][0]-1; j<commands[i][1]; ++j)
			temp.push_back(array[j]);
		int idx = commands[i][2];
        
		sort(temp.begin(), temp.end());
		answer.push_back(temp[idx-1]);
		temp.clear();
	}
	return answer;
}

int main() {
	solution({ 1, 5, 2, 6, 3, 7, 4 }, { {2,5,3},{4,4,1},{1,7,3} });
	return 0;
}