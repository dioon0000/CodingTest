#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int distant[MAX][MAX];
int n, m;

void floydWarshal(){
	for(int x=1; x<=n; ++x)
		distant[x][x] = 0;

	//distant[s][e]를 거쳐가는 i값은 항상 for문의 제일 위에 위치하여야한다
	for(int i=1; i<=n; ++i)
		for(int s=1; s<=n; ++s)
			for(int e=1; e<=n; ++e)
				//distant[s][e]가 -1일 경우
				if(distant[s][e] == -1){
					//[s][i], [i][e] 둘중 하나라도 -1이면 거리를 구할수 없으므로 continue
					if(distant[s][i] == -1 || distant[i][e] == -1)
						continue;
					else
						distant[s][e] = distant[s][i] + distant[i][e];
				}
				else{
					if(distant[s][i] == -1 || distant[i][e] == -1)
						continue;
					else{
						if(distant[s][e] > distant[s][i] + distant[i][e])
							distant[s][e] = distant[s][i] + distant[i][e];
					}
				}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	memset(distant, -1, sizeof(distant));

	//Distant 배열 비용 삽입 for문
	for(int i=0; i<m; ++i){
		int a, b, c;
		cin >> a >> b >> c;

		if(distant[a][b] == -1){
			distant[a][b] = c;
		}
		else
			if(distant[a][b] > c){
				distant[a][b] = c;
			}
	}
	floydWarshal();

	//플로이드 워셜 알고리즘을 통하여 모든 정점간의 최소 비용 표시
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(distant[i][j] == -1)
				cout << 0 << ' ';
			else
				cout << distant[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}