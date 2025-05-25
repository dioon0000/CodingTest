#include <iostream>
using namespace std;

int solution(int n1, int n2){
	int ans;
	if (n1 == n2)
		ans = 1;
	else ans = -1;
	return ans;
}
int main() {
	ios::sync_with_stdio(0);

	int n1, n2;
	cin >> n1 >> n2;
	cout << solution(n1, n2);
	return 0;
}