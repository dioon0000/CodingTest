#include <iostream>
using namespace std;

bool solution(int x) {
	int sum = 0;
	int val = x;
	while(val >= 10) {
		sum+=val%10;
		val/=10;
	}
	sum+=val;
	if(x%sum==0)
		return true;
	else
		return false;
}

int main() {
	solution(12);
	return 0;
}