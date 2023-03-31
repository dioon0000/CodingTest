#include <iostream>
using namespace std;

int arr[100005];
void bubble_sort(int n, int k){
	int swap = 0, cnt = 0, tmp;
	for(int i=0; i<n; ++i){
		cin >> tmp;
		arr[i] = tmp;
	}
	for(int i=n-1; i>0; --i){
		for(int j=0; j<i; ++j){
			if(arr[j]>arr[j+1]){
				swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
				if(++cnt == k){
					cout << arr[j] << ' ' << arr[j+1];
					return;
				}
			}
		}
	}
	cout << -1;
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	bubble_sort(n, k);
	return 0;
}