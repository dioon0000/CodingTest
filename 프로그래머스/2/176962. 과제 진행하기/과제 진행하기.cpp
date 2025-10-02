#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> a, vector<string> b)
{
	return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	vector<pair<string, int>> waitTesk;
	sort(plans.begin(), plans.end(), compare);;

	int time=0;

	for(vector<string> v : plans) {
		int newTime= 60*stoi(v[1].substr(0, 2)) + stoi(v[1].substr(3, 2));

		while(time < newTime) {
			if(waitTesk.size() > 0) {
				waitTesk.back().second--;
				if(waitTesk.back().second==0) {
					answer.push_back(waitTesk.back().first);
					waitTesk.pop_back();
				}
			}
			time++;
		}

		waitTesk.push_back(make_pair(v[0], stoi(v[2])));
	}

	while(waitTesk.size()>0) {
		answer.push_back(waitTesk.back().first);
		waitTesk.pop_back();
	}
	return answer;
}