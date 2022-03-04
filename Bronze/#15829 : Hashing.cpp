#include <bits/stdc++.h>
#define M 1234567891
using namespace std;

int main() {
	int len;
	string str;
	unsigned long long hash = 0, R = 1;

	cin >> len;	cin >> str;

	for (int i = 0; i < len; ++i) {
		hash = (hash + (str[i] - 'a' + 1) % M * R) % M;
		R = R * 31 % M;
	}
	cout << hash;
	return 0;
}