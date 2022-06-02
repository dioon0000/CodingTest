#include <iostream>
using namespace std;

void func(int n, int k, int len){
	int broad_len = 2*len+(k+3);
	//Base Condition
	if(n<=3){
		if(n==1){
			cout << 'm';
			return;
		}
		else{
			cout << 'o';
			return;
		}
	}
	//Recursion func
	if(broad_len<n){
		func(n, k+1, broad_len);
	}
	else{
		if(len<n && n<=len+k+3){
			if(n-len == 1){
				cout << 'm';
				return;
			}
			else{
				cout << 'o';
				return;
			}
		}
		else
			func(n-(len+k+3), 1, 3);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	func(n, 1, 3);
	return 0;
}