#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;

int n, c, num;
map<int, int> idxm; // {숫자, 처음나온 인덱스}
map<int, int> freqm; // {숫자, 빈도}
vector<pair<int, int>> v; // {빈도, 숫자} 를 저장하는 벡터

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.F == b.F)
		return idxm[a.S] < idxm[b.S];
	return a.F > b.F; //빈도 순으로 내림차순 정렬
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; ++i) {
		cin >> num;
		freqm[num]++;
		if (idxm[num] == 0)
			idxm[num] = i + 1;
	}

	for (auto &iter : freqm)
		v.emplace_back(iter.S, iter.F);

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[i].F; ++j)
			cout << v[i].S << " ";

	return 0;
}
