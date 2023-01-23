#include <bits/stdc++.h>
using namespace std;

void heart(){
	cout << " @@@   @@@ \n";
	cout << "@   @ @   @\n";
	cout << "@    @    @\n";
	cout << "@         @\n";
	cout << " @       @ \n";
	cout << "  @     @  \n";
	cout << "   @   @   \n";
	cout << "    @ @    \n";
	cout << "     @     \n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
		heart();
	return 0;
}