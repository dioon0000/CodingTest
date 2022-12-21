#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[3] = {0}, swap;
	cin >> arr[0]; cin >> arr[1]; cin >> arr[2];
	//Bubble Sort
	for(int i=0; i<3; ++i){
		for(int j=i+1; j<3; ++j){
			if(arr[i] > arr[j]){
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}

	cout << arr[1];
	return 0;
}