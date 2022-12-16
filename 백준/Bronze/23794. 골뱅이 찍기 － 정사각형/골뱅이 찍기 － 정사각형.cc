#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=1; i<=n+2; ++i){
		if(i == 1 || i == n+2){
			for(int j=0; j<n+2; ++j)
				cout << "@";
			cout << '\n';
		}
		else{
			for(int j=0; j<n+2; ++j){
				if(j==0 || j == n+1)
					cout << "@";
				else
					cout << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}