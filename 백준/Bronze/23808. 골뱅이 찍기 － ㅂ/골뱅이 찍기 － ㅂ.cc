#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	//1
	for(int i=0; i<2*n; ++i){
		for(int j=0; j<5*n; ++j){
			if(1*n <= j && j < 4*n)
				cout << " ";
			else
				cout << "@";
		}
		cout << '\n';
	}
	//2
	for(int i=0; i<n; ++i){
		for(int j=0; j<5*n; ++j){
			cout << "@";
		}
		cout << '\n';
	}
	//3
	for(int i=0; i<n; ++i){
		for(int j=0; j<5*n; ++j){
			if(1*n <= j && j < 4*n)
				cout << " ";
			else
				cout << "@";
		}
		cout << '\n';
	}
	//4
	for(int i=0; i<n; ++i){
		for(int j=0; j<5*n; ++j){
			cout << "@";
		}
		cout << '\n';
	}
	return 0;
}