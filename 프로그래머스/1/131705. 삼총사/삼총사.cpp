#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i=0; i<number.size()-2; ++i){
        int a = number[i];
        for(int j=i+1; j<number.size()-1; ++j){
            int b = number[j];
            for(int k=j+1; k<number.size(); ++k){
                int c = number[k];
                if(a+b+c==0)
                    answer+=1;
            }
        }
    }
    return answer;
}