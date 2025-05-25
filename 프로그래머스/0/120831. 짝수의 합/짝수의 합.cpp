#include <iostream>
using namespace std;

int solution(int n){
	int e = 0;
	for(int i=1; i<=n; ++i){
		if(i%2==0)
			e+=i;
	}
	return e;
}
int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	cout << solution(n);
	return 0;
	
}