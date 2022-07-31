#include <iostream>
using namespace std;

int func(int n, int r, int c){
	int x = (1<<n-1);
	//Base Condition
	if(n == 0)	return 0;

	//Recursion func
	if(r<x && c<x)	return func(n-1, r, c); //왼쪽 위
	if(r<x && c>=x)	return (x*x)+func(n-1, r, c-x); //오른쪽 위
	if(r>=x && c<x)	return 2*(x*x)+func(n-1, r-x, c); //왼쪽 아래
	if(r>=x && c>=x)	return 3*(x*x)+func(n-1, r-x, c-x); //오른쪽 아래

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c; //r은 행, c는 열
	cin >> n >> r >> c;

	cout << func(n, r, c);
	return 0;
}
