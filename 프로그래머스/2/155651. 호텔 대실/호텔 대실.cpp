#include <bits/stdc++.h>
using namespace std;

int getTime(string str) {
	return stoi(str.substr(0, 2))*60 + stoi(str.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
	vector<pair<int, int>> room;

	for(auto book : book_time) {
		room.push_back({ getTime(book[0]), getTime(book[1])+10});
	}

	sort(room.begin(), room.end());
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<room.size(); ++i) {
		if(!pq.empty() && pq.top() <= room[i].first) {
			pq.pop();
		}

		pq.push(room[i].second);
	}

	return pq.size();
}