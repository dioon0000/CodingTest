#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	int x, l, r;
	cin >> x >> l >> r;

	if (x <= l){
		cout << l << "\n";
	}
	else if (x >= r){
		cout << r << "\n";
	}
	else{
		cout << x << "\n";
	}

	return 0;
}