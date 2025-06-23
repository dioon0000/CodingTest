#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0, size = want.size();
	unordered_map<string, int> m;

	for(int i=0; i<size; ++i)
	{
		m[want[i]] = number[i];
	}

	/* for(auto a : m)
	 {
	 	cout << a.first << ' ' << a.second << '\n';
	 }*/
	for(int i=0; i<=discount.size()-10; ++i)
	{
		unordered_map<string, int> cmp;
		bool flag = false;
		for(int j=0; j<10; ++j)
		{
			cmp[discount[i+j]]+=1;
		}
		/*for(auto c : cmp)
		{
			cout << c.first << ' ' << c.second << ' ';
		}
		cout << '\n';*/
		for(auto x : m)
		{
			//불가능의 경우
			if(x.second > cmp[x.first])
			{
				flag = true;
				break;
			}
		}
		if(!flag)
			answer++;
	}

	cout << answer;
	return answer;
}