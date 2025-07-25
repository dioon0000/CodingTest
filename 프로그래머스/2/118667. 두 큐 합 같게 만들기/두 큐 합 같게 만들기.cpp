#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -1; int cnt = 0;
	long long sum1 = 0; long long sum2 = 0;
	queue<int> q1; queue<int> q2;

	for(int val : queue1) {
		sum1+=val;
		q1.push(val);
	}

	for(int val : queue2) {
		sum2+=val;
		q2.push(val);
	}

	// 합이 홀수라면 어떤 방식으로도 절반으로 맞출 수 없음
	if((sum1+sum2)&1) return answer;

	int maxCnt = (queue1.size()+queue2.size()) * 2;
	while(cnt <= maxCnt) {
		if(sum1 == sum2) {
			answer = cnt;
			return answer;
		}
		else if(sum1 > sum2) {
			if(q1.empty()) break;

			sum1-=q1.front(); sum2+=q1.front();

			q2.push(q1.front());
			q1.pop();
			cnt++;
		}
		else {
			if(q2.empty()) break;

			sum2-=q2.front(); sum1+=q2.front();

			q1.push(q2.front());
			q2.pop();
			cnt++;
		}
	}

	return -1;
}

int main() {
	solution({ 1,1 }, { 1,5 });
	return 0;
}