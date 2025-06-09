#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer; //유효기간이 만료된 자료의 idx를 보관하는 벡터
	vector<int> date; //today의 값을 YEAR, MONTH, DAY로 보관하는 벡터
	vector<int> preDate(3, 0); //개인정보 수집일자를 담은 벡터
	map<string, int> termsMap; //terms의 값을 KEY, VALUE로 보관하는 벡터
	stringstream ss(today); //stringstream ss 값을 분리할때 사용할 변수
	string word; //값을 분리할때 저장할 스트링 변수
	int value; //값을 분리할때 저장할 인트형 변수

	//today 분리
	//date[0],[1],[2]순으로 Year, Month, Day
	while(getline(ss, word, '.'))
		date.push_back(stoi(word));

	//terms의 값들 분리
	for(int i=0; i<terms.size(); ++i){
		ss.clear();
		ss.str(terms[i]);
		//terms 벡터의 문자열을 각각 key, value로 나눔
		while(ss >> word >> value)
			termsMap[word] = value;
	}

	//privacies의 값들 분리
	for(int i=0; i<privacies.size(); ++i){
		preDate.clear();
		int temp = 0;
		string scomDate, alpha;

		//날짜와 약관 종류 분리
		ss.clear();
		ss.str(privacies[i]);
		ss >> scomDate >> alpha;
		//날짜에서 .을 빼고 year,month,day를 분리
		ss.clear();
		ss.str(scomDate);
		while(getline(ss, word, '.')){
			preDate.push_back(stoi(word));
		}

		value = termsMap[alpha]; //Key에 해당하는 value값 저장
		temp = preDate[1]+value; //month+value
		//temp값이 12월 이상일때
		if(temp >= 12){
			//temp값이 12로 나누어 떨어지는 수 일때
			if(temp%12==0){
				preDate[0]+=(temp/12)-1;
				preDate[1]=12;
			}
			else{
				preDate[0]+=(temp)/12;
				preDate[1]=(temp)%12;
			}
		}
		//temp값이 12월 미만일때
		else{
			preDate[1]+=value;
		}

		//Year 비교
		if(preDate[0] < date[0]){
			answer.push_back(i+1);
		}
		else if(preDate[0] == date[0]){
			//Month 비교
			if(preDate[1] < date[1]){
				answer.push_back(i+1);
			}
			else if(preDate[1] == date[1]){
				//Day 비교
				if(preDate[2] <= date[2]){
					answer.push_back(i+1);
				}
			}
		}
	}
	return answer;
}