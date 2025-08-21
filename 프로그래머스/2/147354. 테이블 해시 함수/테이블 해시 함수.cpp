#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	vector<int> sum;

	sort(data.begin(), data.end(),
		 [col](const vector<int>& a, const vector<int>& b) 
		 {
			 if(a[col-1] == b[col-1])
			 {
				 return a > b;
			 }
			 return a[col-1] < b[col-1];	
		 }
	);

	for(int i=row_begin-1; i<row_end; ++i){
		int tempSum=0;
		for(int j=0; j<data[i].size(); ++j) {
			tempSum+=data[i][j]%(i+1);
		}
		sum.push_back(tempSum);
	}
	
	int hash = 0;
	if(sum.size() == 1)
		hash = sum[0];
	else {
		hash = sum[0] ^ sum[1];
		for(int i=2; i<sum.size(); ++i) {
			hash^=sum[i];
		}
	}

	return hash;
}