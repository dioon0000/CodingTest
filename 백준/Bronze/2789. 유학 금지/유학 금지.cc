#include <iostream>
#include <string>
using namespace std;

int main(){
	string cmp = "CAMBRIDGE";
	string str;
	cin >> str;
	for(int i=0; i<cmp.length(); ++i)
		str.erase(remove(str.begin(), str.end(), cmp[i]), str.end());
	cout << str;
	return 0;
}