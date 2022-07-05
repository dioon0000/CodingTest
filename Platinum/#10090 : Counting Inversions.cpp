//https://www.acmicpc.net/problem/10090
#include <bits/stdc++.h>
using namespace std;

int arr[1000005], temp[1000005], n;
long long res=0;

void Merge(int list[], int left, int mid, int right){
	int i, j, k;
	i = left;
	j = mid+1;
	k = left;

	while(i<=mid && j<=right){
		if(list[i] <= list[j])
			temp[k++] = list[i++];
		else{
			temp[k++] = list[j++];
			res+=(mid-i+1); //Inversion Counting (https://salepark.tistory.com/11)
		}
	}

	while(i<=mid)
		temp[k++] = list[i++];

	while(j<=right)
		temp[k++] = list[j++];

	for(int x = left; x<=right; ++x)
		list[x] = temp[x];
}

void MergeSort(int list[], int left, int right){
	int mid;

	if(left < right){
		mid = (left+right)/2;

		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}

	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> arr[i];

	MergeSort(arr, 0, n-1);
	cout << res;
	return 0;
}
