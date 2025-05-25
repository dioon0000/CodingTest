#include <iostream>
using namespace std;

int solution(int num1, int num2) {
	int answer = 0;
	answer = num1 * num2;
	return answer;
}
int main() {
	ios::sync_with_stdio(0);

	int n1, n2, s;
	cin >> n1 >> n2;
	cout << solution(n1, n2);
	return 0;
}