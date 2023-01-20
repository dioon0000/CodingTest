#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	for(int i=0; i<str.length(); ++i){
		if(i == 0){
			if(str[i] == '0')
				cout << "0";
			if(str[i] == '1')
				cout << "1";
			else if(str[i] == '2')
				cout << "10";
			else if(str[i] == '3')
				cout << "11";
			else if(str[i] == '4')
				cout << "100";
			else if(str[i] == '5')
				cout << "101";
			else if(str[i] == '6')
				cout << "110";
			else if(str[i] == '7')
				cout << "111";
		}
		else{
			if(str[0] == '0' && str[i] == '0')
				continue;
			if(str[i] == '0')
				cout << "000";
			else if(str[i] == '1')
				cout << "001";
			else if(str[i] == '2')
				cout << "010";
			else if(str[i] == '3')
				cout << "011";
			else if(str[i] == '4')
				cout << "100";
			else if(str[i] == '5')
				cout << "101";
			else if(str[i] == '6')
				cout << "110";
			else if(str[i] == '7')
				cout << "111";
		}
	}
	return 0;
}