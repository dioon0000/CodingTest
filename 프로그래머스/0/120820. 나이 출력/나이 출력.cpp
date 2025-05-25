#include <iostream>
#define YEAR 2022
using namespace std;

int solution(int age) {
	int answer = 0;
	answer = YEAR - age + 1;
	return answer;
}
int main() {
	ios::sync_with_stdio(0);

	int age;
	cin >> age;
	cout << solution(age);
	return 0;
}