#include <iostream>
using namespace std;

int solution(int n1, int n2){
	return (double) n1 / n2 * 1000;
}
int main() {
	ios::sync_with_stdio(0);

	int n1, n2;
	cin >> n1 >> n2;
	cout << solution(n1, n2);
	return 0;
	
}