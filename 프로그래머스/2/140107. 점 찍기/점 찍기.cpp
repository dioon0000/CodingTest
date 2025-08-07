#include <bits/stdc++.h>
using namespace std;

// x^2 + y^2 = d^2
// y^2 = d^2 - x^2
// y = sqrt(d^2 - x^2)

long long solution(int k, int d) {
	long long answer = 0;

	for(int x=0; x<=d; x+=k) {
		long long maxY = sqrt((long long)d*d - (long long)x*x);
		answer+=maxY/k+1;
	}
	return answer;
}