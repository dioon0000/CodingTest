#include <string>
#include <vector>

using namespace std;

string solution(vector<string> su, vector<int> ch) {
	string ans = "";
	bool re = false; //역순체크
	vector<int> cnt (8, 0); // R T C F J M A N 순
	int x = -1;
	for(int i=0; i<su.size(); ++i){
		if(su[i] == "RT" || su[i] == "TR"){
			x = 0;
			if(su[i] == "TR")
				re = true;
		}
		else if(su[i] == "CF" || su[i] == "FC"){
			x = 1;
			if(su[i] == "FC")
				re = true;
		}
		else if(su[i] == "JM" || su[i] == "MJ"){
			x = 2;
			if(su[i] == "MJ")
				re = true;
		}
		else if(su[i] == "AN" || su[i] == "NA"){
			x = 3;
			if(su[i] == "NA")
				re = true;
		}
		//역순이라면
		if(re){
			if(ch[i] == 1)
				cnt[(x*2)+1] += 3;
			else if(ch[i] == 2)
				cnt[(x*2)+1] += 2;
			else if(ch[i] == 3)
				cnt[(x*2)+1] += 1;
			else if(ch[i] > 4)
				cnt[(x*2)] += ch[i]-4;
			re = false;
		}
		//역순이 아니라면
		else{
			if(ch[i] == 1)
				cnt[(x*2)] += 3;
			else if(ch[i] == 2)
				cnt[(x*2)] += 2;
			else if(ch[i] == 3)
				cnt[(x*2)] += 1;
			else if(ch[i] > 4)
				cnt[(x*2)+1] += ch[i]-4;
		}
	}

	if(cnt[0] >= cnt[1])
		ans+='R';
	else
		ans+='T';
	if(cnt[2] >= cnt[3])
		ans+='C';
	else
		ans+='F';
	if(cnt[4] >= cnt[5])
		ans+='J';
	else
		ans+='M';
	if(cnt[6] >= cnt[7])
		ans+='A';
	else
		ans+='N';

	return ans;
}