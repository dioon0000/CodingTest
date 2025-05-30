#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
	int answer = 0, cnt=1, b=1;
	sort(score.begin(), score.end(), greater<int>());

	for(int i = 0; i < score.size(); ++i) {
		if(cnt%m == 0) {
			answer+=score[cnt*b-1]*m;
			cnt=1; b++;
		}
		else    cnt++;
	}
	return answer;
}