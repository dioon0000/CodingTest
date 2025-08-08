#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
	int answer = 0;
	while(storey>0) {
		int val;
		val = storey % 10;

		if(val>5) { 
			int addVal = 10-val;
			answer += addVal;
			storey+=addVal;
		}
		else if(val == 5) {
			int nextVal = storey%100/10;
			if(nextVal>=5) {
				int addVal = 10-val;
				answer += addVal;
				storey+=addVal;
			}
			else {
				answer += val;;
			}
		}
		else { 
			answer += val; 
		}

		storey/=10;
	}
	return answer;
}