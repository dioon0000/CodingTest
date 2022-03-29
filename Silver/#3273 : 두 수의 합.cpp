#include <iostream>
#include <algorithm>
using namespace std;

//Array max size
//char,bool의 경우   : 최대 약 10^8, 1억
//int의 경우         : 최대 약 25만
//vector의 경우      : 최대 약 10^9, 10억

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, cnt=0;
	cin >> n;
	int* arr = new int[n];
	bool* freq = new bool[2000001]{};

	for (int i = 0; i < n; ++i) //O(n)
		cin >> arr[i];

	cin >> x;

	for (int i = 0; i < n; ++i) { //O(n)
		if (x - arr[i] > 0 && freq[x - arr[i]])
			cnt++;
		freq[arr[i]] = true;
	}

	cout << cnt;
	delete[] arr;
	delete[] freq;
	return 0;
}