//https://www.acmicpc.net/problem/12833
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, ans;
	cin >> a >> b >> c;
	
	if(c%2)
        ans = a^b;
    else
        ans = a;
    
	cout << ans;
	return 0;
}
