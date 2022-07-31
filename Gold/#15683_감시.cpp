//https://www.acmicpc.net/problem/15683
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1e9
using namespace std;
void fill(int r, int c, int dir);
void unfill(int temp[9][9]);
void DFS(int cnt); //cnt값은 현재 v[cnt]에 위치한 CCTV를 설정한 개수값을 의미함
int countMap();
int n, m, map[9][9], ans = MAX;
vector<pair<int, int> > v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j){
			cin >> map[i][j];
			if(map[i][j]!=0 && map[i][j]!=6)
				v.push_back({i, j});
		}

	DFS(0); //처음에 설정한 CCTV값은 0
	cout << ans << '\n';
	return 0;
}

void DFS(int cnt) {
	//Base Condition
	if(cnt == v.size()){
		ans = min(ans, countMap());
		return;
	}

	int r = v[cnt].first, c = v[cnt].second, temp[9][9];
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			temp[i][j] = map[i][j];
		}
	}

	//Recursion Func
	if(map[r][c] == 1){ //1번 CCTV
		for(int i=1; i<=4; ++i){
			fill(r, c, i);
			DFS(cnt+1);
			unfill(temp);
		}
	}
	else if(map[r][c] == 2){ //2번 CCTV
		fill(r, c, 1);	fill(r, c, 2); //동서
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 3);	fill(r, c, 4); //남북
		DFS(cnt+1);
		unfill(temp);
	}
	else if(map[r][c] == 3){ //3번 CCTV
		fill(r, c, 1);	fill(r, c, 3); //동남
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 2);	fill(r, c, 3); //남서
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 2);	fill(r, c, 4); //서북
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 1);	fill(r, c, 4); //북동
		DFS(cnt+1);
		unfill(temp);
	}
	else if(map[r][c] == 4){ //4번 CCTV
		fill(r, c, 1);	fill(r, c, 2);	fill(r, c, 3); //동남서
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 2);	fill(r, c, 3);	fill(r, c, 4); //남서북
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 1);	fill(r, c, 2);	fill(r, c, 4); //서북동
		DFS(cnt+1);
		unfill(temp);

		fill(r, c, 1);	fill(r, c, 3);	fill(r, c, 4); //북동남
		DFS(cnt+1);
		unfill(temp);
	}
	else{ //5번 CCTV
		for(int i=1; i<=4; ++i)	fill(r, c, i); //동서남북
		DFS(cnt+1);
		unfill(temp);
	}
}

void fill(int r, int c, int dir) {
	if(dir == 1){ //동 (r은 그대로, c는 +1)
		for(int i=c+1; i<=m; ++i){
			if(map[r][i] == 6)	break;
			else if(map[r][i])	continue;
			else
				map[r][i] = 7; //7은 CCTV가 확인한 지역을 의미
		}
	}
	if(dir == 2){ //서 (r은 그대로 c는 -1)
		for(int i=c-1; i>=1; i--){
			if(map[r][i] == 6)	break;
			else if(map[r][i])	continue;
			else
				map[r][i] = 7;
		}
	}
	if(dir == 3){ //남 (r+1, c는 그대로)
		for(int i=r+1; i<=n; ++i){
			if(map[i][c] == 6)	break;
			else if(map[i][c])	continue;
			else
				map[i][c] = 7;
		}
	}
	if(dir == 4){ //북 (r-1, c는 그대로)
		for(int i=r-1; i>=1; i--){
			if(map[i][c] == 6)	break;
			else if(map[i][c])	continue;
			else
				map[i][c] = 7;
		}
	}
	return;
}

void unfill(int temp[9][9]) { // 채웠던 map을 이전 상태로 돌려놓는 함수
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			map[i][j] = temp[i][j];

	return;
}

int countMap(){ // 사각지대의 크기를 구하는 함수
	int res = 0;

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(!map[i][j]) //0일 경우 CCTV가 감시하지 못하는 사각지대이므로 result값을 올려줌
				res++;

	return res;
}
