#include <bits/stdc++.h>

using namespace std;

// 상 하 좌 우 대각
const int dy[8] = { -1,1,0,0,-1,-1,1,1 };
const int dx[8] = { 0,0,-1,1,-1,1,-1,1 };

bool check(vector<string> place)
{
	for(int i=0; i<place.size(); ++i)
	{
		for(int j=0; j<place[i].size(); ++j)
		{
			// P를 기준으로 멘헤튼 거리 구간 탐색
			if(place[i][j] == 'P')
			{
				vector<char> info(4, ' ');
				// 상하 좌우
				for(int k=0; k<4; ++k)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					// 구역을 벗어나면 안됨
					if(ny>=0 && ny<place.size() && nx>=0 && nx<place[i].size())
					{
						if(place[ny][nx] == 'P')
							return false;
						info[k] = place[ny][nx];
					}
				}
				// 두칸씩 체크
				for(int k=0; k<4; ++k)
				{
					int ny = i + (dy[k]*2);
					int nx = j + (dx[k]*2);
					// 구역을 벗어나면 안됨
					if(ny>=0 && ny<place.size() && nx>=0 && nx<place[i].size())
					{
						// P라면 앞칸 체크
						if(place[ny][nx] == 'P')
						{
							if(info[k] != 'X')
								return false;
						}
					}
				}
				// 대각선 체크
				for(int k=4; k<8; ++k)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					// 구역을 벗어나면 안됨
					if(ny>=0 && ny<place.size() && nx>=0 && nx<place[i].size())
					{
						if(place[ny][nx] == 'P')
						{
							if(k == 4) // 왼쪽 위 대각선
							{
								// info 상하좌우 저장
								if(info[0] != 'X' || info[2] != 'X')
									return false;
							}
							else if(k == 5) // 오른쪽 위 대각선
							{
								if(info[0] != 'X' || info[3] != 'X')
									return false;
							}
							else if(k == 6) // 왼쪽 아래 대각선
							{
								if(info[1] != 'X' || info[2] != 'X')
									return false;
							}
							else if(k == 7) // 오른쪽 아래 대각선
							{
								if(info[1] != 'X' || info[3] != 'X')
									return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	// 각 대기실
	for(vector<string> place : places)
	{
		bool flag = check(place);
		if(flag)
			answer.push_back(1);
		else
			answer.push_back(0);
	}
	return answer;
}