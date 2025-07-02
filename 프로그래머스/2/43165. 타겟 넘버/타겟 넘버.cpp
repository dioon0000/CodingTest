#include <vector>

using namespace std;
    
int answer = 0;

void dfs(const vector<int>& numbers, int target, int sum, int index) {
	if(numbers.size() == index) {
		if(target == sum) {
			answer++;
		}
		return;
	}

	dfs(numbers, target, sum+numbers[index], index+1);
	dfs(numbers, target, sum-numbers[index], index+1);
}

int solution(vector<int> numbers, int target){
	dfs(numbers, target, 0, 0);
	return answer;
}