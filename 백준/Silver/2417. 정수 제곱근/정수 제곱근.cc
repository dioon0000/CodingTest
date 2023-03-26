#include <iostream>
#include <math.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, q;
	cin >> n;
	q = sqrt(n);
	
	//sqrt()는 double형을 기본 자료형으로 사용하므로 소수 부분의 손실 발생, 따라서 q*q가 n보다 작다면 정수값을 1 올려줌
	if((q*q)<n)
		q+=1;
	cout << q;
	return 0;
}