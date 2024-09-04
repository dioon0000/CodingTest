#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int n, ans;
int h[100005];
stack<int> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	//25번 줄에서 idx값이 1일때 식에서 오류가나므로 초기값 0을 대입해줌
	s.push(0);
	for(int i=1; i<=n; ++i)
		cin >> h[i];

	//ex) 1 2 3 4 5 6 히스토그램의 경우 while문에 걸리지 않으므로 전역변수의 특징을 이용하여 초기화하지않은 주소의 값에는 모두 0이 들어있는 것을 이용
	for(int i=1; i<=n+1; ++i){
		while(!s.empty() && h[s.top()]>h[i]){
			int idx = s.top();
			s.pop();
			ans = max(ans, h[idx]*(i-s.top()-1));
		}
		s.push(i);
	}

	cout << ans;
	return 0;
}