#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int idx = topping.size()/2;
    map<int, int> obro;
    map<int, int> ybro;

    for(int i=0; i<topping.size(); ++i) {
        ybro[topping[i]]++;
    }

    for(int i=0; i<topping.size(); ++i) {
        obro[topping[i]]++;
        if(ybro[topping[i]]-1 <= 0) {
            ybro.erase(topping[i]);
        }
        else {
            ybro[topping[i]]--;
        }

        if(obro.size() == ybro.size())
            answer++;
    }
    
    return answer;
}