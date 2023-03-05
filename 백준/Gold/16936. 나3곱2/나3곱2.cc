#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
long long sel, tmp;
vector<long long> ans;
vector<long long> b;
int visit[105];
void DFS(long long sel, int cnt){
	if(cnt == n){
		for(int i=0; i<n; ++i){
			cout << ans[i] << ' ';
		}
		return;
	}

	//sel*2값이 vector b안에 존재하고, 그 원소를 방문하지 않았을 경우
	if(b.end() != find(b.begin(), b.end(), sel*2) && visit[find(b.begin(), b.end(), sel*2) - b.begin()] == 0){
		visit[find(b.begin(), b.end(), sel*2) - b.begin()] = 1;
		ans.push_back(sel*2);
		DFS(sel*2, cnt+1);
		ans.pop_back();
	}
	if(sel%3 == 0){
		//sel/3값이 vector b안에 존재하고, 그 원소를 방문하지 않았을 경우
		if(b.end() != find(b.begin(), b.end(), sel/3) && visit[find(b.begin(), b.end(), sel/3) - b.begin()] == 0){
			ans.push_back(sel/3);
			DFS(sel/3, cnt+1);
			ans.pop_back();
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> tmp;
		b.push_back(tmp);
	}

	//Brute Force Algorithm
	for(int i=0; i<n; ++i){
		fill_n(visit, 105, 0);
		sel = b[i];
		ans.push_back(sel);
		DFS(sel, 1);
		ans.pop_back();
	}
	return 0;
}