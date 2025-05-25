#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> v){
	double ans = 0;
	for(int i=0; i<v.size(); ++i){
		ans+=v[i];
	}
	return ans/v.size();
}