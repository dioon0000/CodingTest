#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		string str;
		int score;
		cin >> str >> score;
		if(score >= 97 && score <= 100)
			cout << str << " A+\n";
		else if(score >= 90 && score <= 96)
			cout << str << " A\n";
		else if(score >= 87 && score <= 89)
			cout << str << " B+\n";
		else if(score >= 80 && score <= 86)
			cout << str << " B\n";
		else if(score >= 77 && score <= 79)
			cout << str << " C+\n";
		else if(score >= 70 && score <= 76)
			cout << str << " C\n";
		else if(score >= 67 && score <= 69)
			cout << str << " D+\n";
		else if(score >= 60 && score <= 66)
			cout << str << " D\n";
		else
			cout << str << " F\n";
	}
	return 0;
}