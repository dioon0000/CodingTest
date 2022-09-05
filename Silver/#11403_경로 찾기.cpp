//https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int graph[MAX][MAX];
int n;

void floyd(){
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(graph[i][k] && graph[k][j])
					graph[i][j] = 1;

	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	//graph 정보 입력
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> graph[i][j];
	
	floyd();

	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}