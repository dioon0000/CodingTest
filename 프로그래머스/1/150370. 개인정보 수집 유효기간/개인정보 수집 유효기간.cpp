#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	vector<int> date; //today의 값들을 분리해 저장해놓을 벡터
	map<string, int> termsMap; //terms의 값들을 분리하여 저장할 벡터
	stringstream ss(today);
	string word;
	int value;

	//today 분리
	while(getline(ss, word, '.'))
		date.push_back(stoi(word));
	//terms의 값들 분리
	for(int i=0; i<terms.size(); ++i){
		ss.clear();
		ss.str(terms[i]);
		while(ss >> word >> value){
			termsMap[word] = value;
		}
	}
	for(int i=0; i<privacies.size(); ++i){
		string scomDate = "";
		vector<int> comDate(3, 0);
		int idx = 0, add = 0, temp = 0;
		string num;
		ss.clear();
		ss.str(privacies[i]);
		ss >> scomDate >> num;
		ss.clear();
		ss.str(scomDate);
		while(getline(ss, word, '.')){
			comDate[idx++] = stoi(word);
		}
		add = termsMap[num];
		temp = comDate[1]+add;
        if(temp >= 12){
	        if(temp%12==0){
		        comDate[0]+=(temp/12)-1;
		        comDate[1]=12;
	        }
	        else{
		        comDate[0]+=(temp)/12;
		        comDate[1]=(temp)%12;
	        }
        }
        else{
	        comDate[1]+=add;
        }
		if(comDate[0] < date[0]){
			answer.push_back(i+1);
		}
		else if(comDate[0] == date[0]){
			if(comDate[1] < date[1]){
				answer.push_back(i+1);
			}
			else if(comDate[1] == date[1]){
				if(comDate[2] <= date[2]){
					answer.push_back(i+1);
				}
			}
		}
	}
	return answer;
}