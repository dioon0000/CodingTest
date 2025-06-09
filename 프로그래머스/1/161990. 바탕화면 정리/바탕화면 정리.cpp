#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	vector<int> x;
	vector<int> y;
	int minx=0, miny=0, maxx=0, maxy=0 ;
	//i = x, j = y
	for(int i=0; i<wallpaper.size(); ++i){
		for(int j=0; j<wallpaper[i].length(); ++j){
			if(wallpaper[i][j] == '#'){
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	answer.push_back(*min_element(x.begin(), x.end()));
	answer.push_back(*min_element(y.begin(), y.end()));
	answer.push_back(*max_element(x.begin(), x.end())+1);
	answer.push_back(*max_element(y.begin(), y.end())+1);
	return answer;
}