#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int len;
	int arr[2] ={0,};
	char word;
	cin >> len;
	for(int i=0; i<len; ++i){
		cin >> word;
		if(word == '2')
			arr[0]++;
		else if(word == 'e')
			arr[1]++;
	}

	if(arr[0] == arr[1])
		cout << "yee";
	else if(arr[0] > arr[1])
		cout << '2';
	else
		cout << 'e';
	return 0;
}