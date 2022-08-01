//https://www.acmicpc.net/problem/1676
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans=0;
	cin >> n;
	
	/*
	Factorial에서 뒤에 0이 나오는 경우는 10이 곱해진 경우밖에 존재하지않는다

	따라서 10의 소인수값인 2, 5중 더 적게 나오는 값이 10의 값이라고 생각하고 구한다

	단, 통념적으로 자연수 n을 소인수분해 하였을 때, 2가 5보다 더 많은 값을 가지고 있으므로 5를 구한다

	n을 i(5^x)로 나누면 n에 5^x가 얼마나 들어있는지 알수있으므로 for문을 이용하여 5의 개수를 찾아내어 출력한다
	*/	
	for(int i=5; i<=n; i*=5)
			ans += n/i;

	cout << ans;
	return 0;
}