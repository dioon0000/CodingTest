#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	vector<int> st;

	for(int i : ingredient){
		if(st.empty()){
			if(i == 1)
				st.push_back(1);
		}
		else{
			if(st.back()!=123 && i == 1){
				st.push_back(1);
			}
			else if(st.back()==1 && i==2){
				st.back() = 12;
			}
			else if(st.back()==12 && i==3){
				st.back() = 123;
			}
			else if(st.back()==123 && i==1){
				answer++;
				st.pop_back();
			}
			else{
				st.clear();
			}
		}
	}
	return answer;
}