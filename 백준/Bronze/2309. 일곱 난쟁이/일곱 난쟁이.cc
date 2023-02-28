#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tmp, sum=0, a, b;
	vector<int> v;
	for(int i=0; i<9; ++i){
		cin >> tmp;
		sum+=tmp;
		v.push_back(tmp);
	}

	for(int i=0; i<8; ++i){
		for(int j=i+1; j<9; ++j){
			if(sum-v[i]-v[j] == 100){
				a = i;
				b = j;
				i=8;
				break;
			}
		}
	}

	v.erase(v.begin()+b);
	v.erase(v.begin()+a);
	sort(v.begin(), v.end());

	for(int i=0; i<7; ++i)
		cout << v[i] << '\n';
	return 0;
}