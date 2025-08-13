#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(a%b==0) return b;
	return gcd(b, a%b);
}

long long solution(int w, int h) {
	long long answer = 1;

	if(w == h) return (long long)w*(long long)w-w;
	else {
		int val = gcd(w, h);
		return (long long)w*(long long)h-(w+h-val);
	}
}