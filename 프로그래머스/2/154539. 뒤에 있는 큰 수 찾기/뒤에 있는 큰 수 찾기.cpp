#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), 0);
    stack<int> st;

    for(int i=numbers.size()-1; i>=0; --i) {
        while(1) {
            //st이 비어있다면 해당 answer[i]보다 큰 수는 존재하지 않음
            if(st.empty()) {
                answer[i] = -1;
                break;
            }
            //st.top이 numbers보다 큰수가 존재할 경우
            if(st.top()>numbers[i]) {
                answer[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(numbers[i]);
    }
    return answer;
}