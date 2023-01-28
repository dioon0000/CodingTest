#include <bits/stdc++.h>
using namespace std;

int alpha[26];
bool odd_flag = false;
bool even_flag = false;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	for(int i=0; i<str.length(); ++i){
		alpha[str[i]-97]++;
	}

	for(int i=0; i<26; ++i){
		if(alpha[i] == 0)
			continue;
		if(alpha[i]%2 == 0)
			even_flag = true;
		if(alpha[i]%2 != 0)
			odd_flag = true;
	}

	if(even_flag && odd_flag)
		cout << 2;
	else if(even_flag)
		cout << 0;
	else if(odd_flag)
		cout << 1;
	return 0;
}