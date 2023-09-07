#include <bits/stdc++.h>
using namespace std;

int arr[500][500];
int n, maxVal=0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<=i; ++j){
			cin >> arr[i][j];
		}
	}

	for(int i=1; i<n; ++i){
		for(int j=0; j<=i; ++j){
			if(j==0)
				arr[i][j]+=arr[i-1][j];
			else if(j==i)
				arr[i][j]+=arr[i-1][j-1];
			else{
				int left, right;
				left = arr[i][j]+arr[i-1][j];
				right = arr[i][j]+arr[i-1][j-1];
				if(left<=right)
					arr[i][j] = right;
				else
					arr[i][j] = left;
			}
		}
	}

	for(int i=0; i<n; ++i){
		if(maxVal < arr[n-1][i])
			maxVal = arr[n-1][i];
	}
	cout << maxVal;
	return 0;
}