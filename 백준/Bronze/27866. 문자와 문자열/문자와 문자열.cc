#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string str;
	cin >> str >> n;
	cout << str[n-1];
	return 0;
}