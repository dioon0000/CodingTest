#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	int n;
	
	cin >> str;
	cin >> n;
	
	list<char> lt(str.begin(), str.end());
	list<char>::iterator cursor = lt.end();
	
	for(int i=0; i<n; ++i){
		char commend;
		cin >> commend;
		
		if(commend == 'L'){
			if(cursor != lt.begin())
				cursor--;
		}
		else if(commend == 'D'){
			if(cursor != lt.end())
				cursor++;
		}
		else if(commend == 'B'){
			if(cursor != lt.begin())
				cursor = lt.erase(--cursor);
		}
		else if(commend == 'P'){
			char tmp;
			cin >> tmp;
			lt.insert(cursor, tmp);
		}
	}
	
	for(list<char>::iterator it = lt.begin(); it != lt.end(); ++it)
		cout << *it;
	return 0;
}