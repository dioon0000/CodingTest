#include <bits/stdc++.h>
#define MAX 105
#define INF 2e9 //2,000,000,000
using namespace std;

int distant[MAX][MAX];
int nxt[MAX][MAX];
int n, m;

void floydWarshal(){
	for(int x=1; x<=n; ++x){
		distant[x][x] = 0;
		nxt[x][x] = 0;
	}

	for(int i=1; i<=n; ++i)
		for(int s=1; s<=n; ++s)
			for(int e=1; e<=n; ++e)
				if(distant[s][e] == INF){
					if(distant[s][i] == INF || distant[i][e] == INF)
						continue;
					else{
						distant[s][e] = distant[s][i] + distant[i][e];
						nxt[s][e] = nxt[s][i];
					}
				}
				else{
					if(distant[s][i] == INF || distant[i][e] == INF)
						continue;
					else{
						if(distant[s][e] > distant[s][i] + distant[i][e]){
							distant[s][e] = distant[s][i] + distant[i][e];
							nxt[s][e] = nxt[s][i];
						}
					}
				}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	fill(&distant[0][0], &distant[n][n+1], INF);
	fill(&nxt[0][0], &nxt[n][n+1], INF);

	//Distant 배열 비용 삽입 for문
	for(int i=0; i<m; ++i){
		int a, b, c;
		cin >> a >> b >> c;

		if(distant[a][b] == INF){
			distant[a][b] = c;
			nxt[a][b] = b;
		}
		else
			if(distant[a][b] > c){
				distant[a][b] = c;
			}
	}
	floydWarshal();

	//distance 테이블의 값들을 출력
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(distant[i][j] == INF){
				cout << 0 << ' ';

			}
			else
				cout << distant[i][j] << ' ';
		}
		cout << '\n';
	}

	//nxt 테이블의 값들을 출력
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i==j)
				cout << 0 << '\n';
			else{
				int cnt = 0, s=i, e=j; //s는 시작노드, e는 도착노드
				int arr[5] = {0,};
				//s에서 e노드로 갈 수없을 때
				if(nxt[s][e] == INF){
					cout << 0 << '\n';
					continue;
				}
				//여러번의 간선을 거쳐 가는경우 cnt값을 올려주기 위한 While문
				do{
					arr[cnt++] = s;
					s = nxt[s][e];
				} while(s != e);
				cout << cnt+1 << " ";
				for(int k=0; k<cnt; ++k){
					cout << arr[k] << " ";
				}
				cout << e <<'\n';
			}
		}
	}
	return 0;
}