#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	for(int i=0; i<str.length(); ++i){
		switch (i){
			case 0:
				if(str[i] == 'E')
					cout << "I";
				else
					cout << "E";
				break;
			case 1:
				if(str[1] == 'S')
					cout << "N";
				else
					cout << "S";
				break;
			case 2:
				if(str[i] == 'T')
					cout << "F";
				else
					cout << "T";
				break;
			case 3:
				if(str[i] == 'P')
					cout << "J";
				else
					cout << "P";
				break;
		}
	}
	return 0;
}