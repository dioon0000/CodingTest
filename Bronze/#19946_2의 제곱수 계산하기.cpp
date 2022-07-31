//https://www.acmicpc.net/problem/19946
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unsigned long long int n;
	int k = 64;
	cin >> n;

	while(n%2==0){
		n>>=1;
		k--;
	}

	cout << k;

	return 0;
}
