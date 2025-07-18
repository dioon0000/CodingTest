#include <iostream>
using namespace std;

int arr[65][65];
void func(int n, int r, int c){
	int black = 0;
	int white = 0;
	//Base Condition
	if(n == 1){
		cout << arr[r][c];
		return;
	}
	for(int i=r; i<r+n; ++i){
		for(int j=c; j<c+n; ++j){
			if(arr[i][j]==0)	white++;
			else if(arr[i][j]==1)	black++;
		}
	}
	if(white == n*n)	cout << 0;
	else if(black == n*n)	cout << 1;
	//Recursion func
	else{
		cout << '(';
		func(n/2, r, c);
		func(n/2, r, c+n/2);
		func(n/2, r+n/2, c);
		func(n/2, r+n/2, c+n/2);
		cout << ')';
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		for(int j=0; j<n; ++j){
			arr[i][j] = s[j] - '0';
		}
	}

	func(n, 0, 0);
	return 0;
}