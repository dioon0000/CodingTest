#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(true){
		int a=0, b=0, tmp;
		cin >> n;
		if(n == 0)
			break;
		for(int i=0; i<n; ++i){
			cin >> tmp;
			if(tmp == 0)
				a+=1;
			else
				b+=1;
		}
		cout << "Mary won " << a << " times and John won " << b << " times\n";
	}
	return 0;
}