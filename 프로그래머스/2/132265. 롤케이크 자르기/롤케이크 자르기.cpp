#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> obro;
    map<int, int> ybro;

    for(int i=0; i<topping.size(); ++i)
        ybro[topping[i]]++;

    for(int i=0; i<topping.size(); ++i) {
        obro[topping[i]]++;
        ybro[topping[i]]--;

        if(ybro[topping[i]] == 0)
            ybro.erase(topping[i]);

        if(obro.size() == ybro.size())
            answer++;
    }
    return answer;
}