#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool even_flag = false, odd_flag = false;
	int alpha[26] = { 0 };
	string str;
	cin >> str;
	for(int i=0; i<str.length(); ++i)
		alpha[str[i]-97]++;
	for(int i=0; i<26; ++i){
		if(alpha[i] == 0)
			continue;
		else if(alpha[i]%2 == 0)
			even_flag = true;
		else if(alpha[i]%2 != 0)
			odd_flag = true;
	}
	if(even_flag && odd_flag)
		cout << "0/1";
	else if(even_flag)
		cout << "0";
	else if(odd_flag)
		cout << "1";
	return 0;
}