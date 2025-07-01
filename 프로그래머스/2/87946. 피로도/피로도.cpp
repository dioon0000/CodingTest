#include <string>
#include <vector>

#define MAX 8
using namespace std;

int answer = -1;
vector<bool> visited(MAX, false);

void dfs(int cnt, int k, vector<vector<int>> dungeons){
	// TODO DFS Why? 백트레킹 기법을 사용해서 아닌 구간을 지워내는 DFS가 적합
	/*
	1. 탐험한 던전 수를 0부터 실행
	2. 만약 최소 필요 피로도가 현재 k값보다 작거나 같다면 해당 던전 방문
	3. 이미 방문했거나 최소 필요 피로도가 현재 K값보다 클때 넘어감
	*/
	if(cnt > answer) answer = cnt;
	for(int i=0; i<dungeons.size(); ++i){
		if(dungeons[i][0] <= k && !visited[i]){
			visited[i] = true;
			dfs(cnt+1, k-dungeons[i][1], dungeons);
			visited[i] = false;
		}

	}
}

int solution(int k, vector<vector<int>> dungeons){
	dfs(0, k, dungeons);

	return answer;
}