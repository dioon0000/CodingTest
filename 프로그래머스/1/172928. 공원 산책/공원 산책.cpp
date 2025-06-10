#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	vector<vector<string>> p(51,vector<string>(51,"X"));
	pair<int, int> s;
	int weight = park[0].length(), height = park.size();

	for(int i=0; i<height; ++i)
		for(int j=0; j<weight; ++j){
			if(park[i][j] == 'S'){
				s = { i,j };
				park[i][j] == 'O';
			}
			p[i][j] = park[i][j];
		}
	for(int i=0; i<routes.size(); ++i){
		stringstream ss(routes[i]);
		char op;
		int n, temp;

		ss >> op >> n;
		//cout << op << ' ' << n << '\n';
		if(op == 'E'){ //y좌표 +
			temp = s.second;
			for(int i=0; i<n; ++i){
				temp+=1;
				if(temp >= weight){
					temp = s.second;
					break;
				}
				if(p[s.first][temp] == "X"){
					temp = s.second;
					break;
				}
			}
			s.second = temp;
		}
		else if(op == 'W'){ //y좌표 -
			temp = s.second;
			for(int i=0; i<n; ++i){
				temp-=1;
				if(temp < 0){
					temp = s.second;
					break;
				}
				if(p[s.first][temp] == "X"){
					temp = s.second;
					break;
				}
			}
			s.second = temp;
		}
		else if(op == 'S'){ //x좌표 +
			temp = s.first;
			for(int i=0; i<n; ++i){
				temp+=1;
				if(temp >= height){
					temp = s.first;
					break;
				}
				if(p[temp][s.second] == "X"){
					temp = s.first;
					break;
				}
			}
			s.first = temp;
		}
		else if(op == 'N'){ //x좌표 -
			temp = s.first;
			for(int i=0; i<n; ++i){
				temp-=1;
				if(temp < 0){
					temp = s.first;
					break;
				}
				if(p[temp][s.second] == "X"){
					temp = s.first;
					break;
				}
			}
			s.first = temp;
		}
	}
	answer.push_back(s.first);
	answer.push_back(s.second);
	return answer;
}