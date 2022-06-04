// https://www.acmicpc.net/problem/2448
// 프렉탈 도형 문제
#include <bits/stdc++.h>
#define ROW_MAX 3073
#define COL_MAX 6144
using namespace std;

char star[ROW_MAX][COL_MAX]; //최대 17MB
void func(int n, int r, int c){

	//Base Condition
	if(n == 3){
		star[r][c] = '*';
		star[r+1][c-1] = '*';
		star[r+1][c+1] = '*';
		star[r+2][c-2] = '*';
		star[r+2][c-1] = '*';
		star[r+2][c] = '*';
		star[r+2][c+1] = '*';
		star[r+2][c+2] = '*';
		return;
	}

	//Recursion Func
	func(n/2, r, c);
	func(n/2, r+(n/2), c-(n/2));
	func(n/2, r+(n/2), c+(n/2));
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	//Default
	for(int i=0; i<n; ++i)
		for(int j=0; j<2*n-1; ++j)
			star[i][j] = ' ';

	func(n, 0, n-1); //기준 점 좌표

	for(int i=0; i<n; ++i){
		for(int j=0; j<2*n-1; ++j){
			cout << star[i][j];
		}
		if(i!=n-1)
			cout << '\n';
	}
	return 0;

}