#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int alpha[26] = {0};
	char al;
	for(int i=0; i<25; ++i){
		cin >> al;
		alpha[al-65]++;
	}
	for(int i=0; i<=25; ++i){
		if(alpha[i] == 0)
			cout << (char)(i+65);
	}
	return 0;
}