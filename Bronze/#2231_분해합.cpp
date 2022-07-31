//Brute Force Algorithm
#include <iostream>
using namespace std;
bool flag = false;

int IntDigits(int tmp, int N) {
	int sum = 0, div = tmp;
	while (div) {
		sum += div % 10;
		div /= 10;
	}
	sum += tmp;
	if (sum == N) {
		flag = true;
		return tmp;
	}
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, constructor = 0;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		constructor = IntDigits(i, n);
		if (flag)
			break;
	}

	cout << constructor;
	return 0;
}
