#include <bits/stdc++.h>
using namespace std;
	/*
	블래스터 라이플	$350.34
	시각 센서	$230.90
	청각 센서	$190.55
	팔	$125.30
	다리	$180.90
	*/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	int t, a, b, c, d, e;
	cin >> t;
	while(t--){
		double sum=0;
		cin >> a >> b >> c >> d >> e;
		sum+=(350.34*a)+(230.9*b)+(190.55*c)+(125.30*d)+(180.9*e);
		cout.setf(ios::fixed); //cout << fixed; 와 같다, 소수점 고정 해제는 cout.unsetf(ios::fixed);
		cout.precision(2);
		cout << '$' << sum << '\n';
	}
	return 0;
}