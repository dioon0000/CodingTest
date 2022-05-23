#include <iostream>
using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll c){
	if(b == 1)	return a%c;
	//a^n * a^n = a^2n 공식을 이용하여 재귀 풀이
	ll val = POW(a, b/2, c);
	val = val * val % c;

	if(b%2==0)	return val;
	return val * a % c;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
  cout << POW(a, b, c);
	return 0;
}
