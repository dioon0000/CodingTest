#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//1 × S + 2 × M + 3 × L
	int s, m, l;
	cin >> s >> m >> l;
	if(1*s+2*m+3*l >= 10)
		cout << "happy";
	else
		cout << "sad";

	return 0;
}