#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	float n;
	cout << fixed;
	cout.precision(2);
	while(1){
		cin >> n;
		if(n == -1)
			break;
		cout << "Objects weighing " << n << " on Earth will weigh " << n*0.167 << " on the moon.\n";
	}
	return 0;
}