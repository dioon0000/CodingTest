#include <iostream>
#define MAX 30
using namespace std;

int n, cnt = 0;
bool visited1[MAX], visited2[MAX], visited3[MAX];

void func(int cur){
	//Base Condition
	if(cur == n){
		cnt++;
		return;
	}

	//Recursion Func
	for(int i=0; i<n; ++i){
		//같은 열을 조사하는 visited1
		if(visited1[i])
			continue;
		//왼쪽 아래로 뻗어가는 visited2
		if(visited2[cur+i])
			continue; 
		//오른쪽 아래로 뻗어가는 visited3
		if(visited3[cur-i+n-1])
			continue;
		visited1[i] = true;
		visited2[cur+i] = true;
		visited3[cur-i+n-1] = true;
		func(cur+1);
		visited1[i] = false;
		visited2[cur+i] = false;
		visited3[cur-i+n-1] = false;
	}
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
	return 0;
}