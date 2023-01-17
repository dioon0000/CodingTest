#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, a, b, c;
	cin >> t;

	while(t--){
		int cnt = 0, min = 100;
		cin >> a >> b >> c;
		if(min > a) min = a;
		if(min > b) min = b;
		if(min > c) min = c;

		cout << min << '\n';
	}
	return 0;
}