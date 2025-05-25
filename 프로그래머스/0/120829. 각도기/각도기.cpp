#include <iostream>
using namespace std;

int solution(int n1){
	if(0<n1 && n1<90)
		return 1;
	else if(n1 == 90)
		return 2;
	else if(90<n1 && n1<180)
		return 3;
	else if(n1 == 180)
		return 4;
}
int main() {
	ios::sync_with_stdio(0);

	int n1;
	cin >> n1;
	cout << solution(n1);
	return 0;
	
}