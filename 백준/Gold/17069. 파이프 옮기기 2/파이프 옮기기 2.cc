#include <bits/stdc++.h>
#define R first
#define C second
#define ll long long
using namespace std;

int n;
int arr[33][33];
ll dp[33][33][3]; // 0 가로, 1 세로, 2 대각선
ll sum = 0;
/*
	시작점은 {1,2} 최대 크기는 32*32
	우선 {x,2}에 위치해있는 좌표들은 항상 0의 값을 가지기 때문에 초기값으로 세팅
	이중 for문의 시작 r,c는 1,3

	<불가능 조건들>
	c가 n일 때 가로(0)는 불가
	r이 n일 때 세로(1)는 불가
	대각선은 {r-1,c}, {r,c-1}의 좌표가 벽(1)이 아닐 때만 위치할 수 있음
*/
void chk(){
	for(int i=1; i<=n; ++i){
		for(int j=3; j<=n; ++j){
			for(int k=0; k<3; ++k){
				if(k==0){ //dp 배열의 가로 블럭을 찾아 계산
					if(arr[i][j]==1 || arr[i][j-1]) //벽으로 막혀있는 경우
						continue;
					if(j==n && i!=n) //가로 블럭이 좌표평면의 최우측의 위치하는 경우
						continue;
					dp[i][j][k]+=dp[i][j-1][0]+dp[i][j-1][2];
				}
				else if(k==1){ //dp 배열의 세로 블럭을 찾아 계산
					if(i==1)
						continue;
					if(arr[i][j]==1 || arr[i-1][j]==1) //벽으로 막혀있는 경우
						continue;
					if(i==n && j!=n) //세로 블럭이 좌표평면의 최하단의 위치하는 경우
						continue;
					dp[i][j][k]+=dp[i-1][j][1]+dp[i-1][j][2];
				}
				else{ //dp 배열의 대각 블럭을 찾아 계산
					if(i==1)
						continue;
					if(arr[i][j]==1 || arr[i-1][j]==1 || arr[i][j-1]==1 || arr[i-1][j-1]==1) //벽으로 막혀있는 경우
						continue;
					dp[i][j][k]+=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> arr[i][j];
		}
	}
	dp[1][2][0] = 1;
	chk();

	sum+=dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
	cout << sum;
	return 0;
}