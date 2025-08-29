#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> cards) {
	int answer = 0, size = cards.size();
	vector<int> groups(size, 0);
	vector<bool> visit(size, false);
	stack<pair<int, int>> box;

	// 1번 상자에서부터 순회 
	for(int i=0; i<size; ++i) {
		if(visit[i]) continue;

		int cnt = 1;
		box.push({ i, cards[i]});
		visit[i] = true;

		while(!box.empty()) {
			int idx = box.top().second-1;
			box.pop();
			// 이미 방문한 곳이라면
			if(visit[idx]) continue;

			// 방문하지 않았다면
			cnt++;
			box.push({ idx, cards[idx] });
			visit[idx] = true;
		}
		groups.push_back(cnt);
	}

	sort(groups.begin(), groups.end(), greater<int>());

	answer = groups[0] * groups[1];
	return answer;
}