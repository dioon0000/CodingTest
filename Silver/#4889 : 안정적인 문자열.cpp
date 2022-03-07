#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> s;
	string str;
	int cnt = 1;
	while (getline(cin, str)) {
		int minValue = 0;
		//무한루프를 끝내기 위한 조건문
		if (str[0] == '-')
			break;

		for (int i = 0; i < str.size(); ++i) {
			//Greedy Algorithm PS
			if (str[i] == '{')
				s.push(str[i]);
			else if (str[i] == '}') {
				if (s.size() > 0 && s.top() == '{') {
					s.pop();
				}
				else {
					minValue++;
					s.push('{');
				}
			}
		}
		if(!s.empty())
			minValue = minValue + (s.size() / 2);

		cout << cnt << ". " << minValue << '\n';
		while (!s.empty())	s.pop();
		cnt++;
	}
	return 0;
}