#include <bits/stdc++.h>
using namespace std;

long long solution(vector<int> weights) {
	long long answer = 0;
	map<int, long long> m;
	for(int i=0; i<weights.size(); ++i) {
		if(m.find(weights[i])!= m.end())
			m[weights[i]]++;
		else
			m.insert({ weights[i], 1 });
	}

	for(int i=0; i<weights.size(); ++i) {
		long long base = 0;

		base = weights[i]*2;
		if(base%3==0 && m.find(base/3)!= m.end())
			answer+=m[base/3];
		if(base%4==0 && m.find(base/4)!= m.end())
			answer+=m[base/4];

		base = weights[i]*3;
		if(base%4==0 && m.find(base/4)!= m.end())
			answer+=m[base/4];

	}
	for(int i=100; i<=1000; ++i) {
		if(m[i]>=2)
			answer+=(m[i]*(m[i]-1)/2);
	}
    
	return answer;
}