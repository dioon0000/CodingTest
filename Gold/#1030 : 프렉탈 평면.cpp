#include <bits/stdc++.h>
#define WHITE 0
#define BLACK 1
using namespace std;

int s, n, k, width = 1;
int r1, r2, c1, c2;

int func(int w, int r, int c){
	//Base Condition
	if(w == 1)
		return WHITE;
	else{
		//k*k범위 내에 있는 경우 1 return
		if(w/n*(n-k)/2<=r && r<w/n*(n+k)/2 && w/n*(n-k)/2<=c && c<w/n*(n+k)/2)
			return BLACK;
	}
	//Recurse Func
	return func(w/n, r%(w/n), c%(w/n)); // func함수는 int형이므로 재귀호출 시 return을 붙여주어야 함 (중요)
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
	while(s--)
		width *= n;
	
	for(int i=r1; i<=r2; ++i){
		for(int j=c1; j<=c2; ++j){
			cout << func(width, i, j);
		}
		cout << '\n';
	}
	return 0;
}