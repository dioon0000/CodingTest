#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(int i=0; i<numbers.size(); ++i) {
        if((numbers[i]&1) == 0) {
            answer.push_back(numbers[i]+1);
        }
        else {
            int idx = 0;
            long long tempValue = numbers[i];

            while(tempValue) {
                if((tempValue&1) == 0 && idx == 0) {
                    answer.push_back(numbers[i]+1);
                    break;
                }
                if((tempValue&1) != 0) {
                    tempValue/=2;
                    idx++;
                }
                else 
                    break;
            }

            numbers[i] |= (1LL << idx);
            numbers[i] &= ~(1LL << idx-1);

            answer.push_back(numbers[i]);
        }
    }
    return answer;
}

int main() {
    solution({ 3,5,7,9 });
    return 0;
}