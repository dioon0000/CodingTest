//https://www.acmicpc.net/problem/15664
//동일된 값이 포함된 조합
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8], ans[8];
bool visited[8];

void func(int num, int cnt){
	if(cnt == m){
		for(int i=0; i<m; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int preNum = -1;
	for(int i=num; i<n; ++i){
		if(!visited[i] && arr[i]!=preNum){
			ans[cnt] = arr[i];
			preNum = ans[cnt];
			visited[i] = true;
			func(i+1, cnt+1);
			visited[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	sort(arr, arr+n);

	func(0, 0);
	return 0;
}