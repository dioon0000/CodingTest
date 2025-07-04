#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<string, int> m; // 차량번호의 입차 시간이 저장됨
	map<string, int> today; // 해당 차량의 하루 주차장 이용시간이 저장됨
	for(string str : records)
	{
		vector<string> split; // [0] = 시간 [1] = 차량번호 [2] = IN/OUT
		vector<int> minute;
		int time = 0;
		stringstream ss(str);
		string word;
		// 문자열 분리를 위한 부분
		while(ss>>word)
		{
			split.push_back(word);
		}

		// 문자열로 되어있는 시간을 분형식으로 저장하기 위한 부분
		ss.str(split[0]);
		ss.clear();
		while(getline(ss, word, ':'))
		{
			//cout << stoi(word) << '\n';
			minute.push_back(stoi(word));
		}
		time = minute[0]*60+minute[1];
		
		// IN 입력이 들어왔을 때
		if(split[2] == "IN")
		{
			m[split[1]] = time;
		}
		// OUT 입력이 들어왔을 때
		if(split[2] == "OUT")
		{
			today[split[1]] += time - m[split[1]];
			// 그전에 IN값으로 들어왔던 정보를 지워줌
			m.erase(split[1]);
		}
	}
	// OUT 내역이 주어지지 않은 차량에 대한 처리
	for(auto iter=m.begin(); iter != m.end(); ++iter)
	{
		today[iter->first]+=(1439 - iter->second);
	}
	// 요금 계산
	for(auto x : today)
	{
		// 기본요금을 초과했다면
		if(x.second > fees[0])
		{
			int fee = 0;
			// 나누어 떨어지지 않는다면
			if((x.second-fees[0])%fees[2] !=0)
			{
				fee = fees[1]+((x.second-fees[0])/fees[2]+1)*fees[3];
			}
			// 나누어 떨어진다면
			else
			{
				fee = fees[1]+((x.second-fees[0])/fees[2])*fees[3];

			}
			answer.push_back(fee);
		}
		// 기본요금을 초과하지 않았다면
		else
		{
			answer.push_back(fees[1]);
		}
	}

	return answer;
}