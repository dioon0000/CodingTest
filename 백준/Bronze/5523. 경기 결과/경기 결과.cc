#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a=0, b=0;
	cin >> n;
	while(n--){
		int x, y;
		cin >> x >> y;
		if(x>y)
			a++;
		else if(x<y)
			b++;
	}
	cout << a << ' ' << b;
	return 0;
}