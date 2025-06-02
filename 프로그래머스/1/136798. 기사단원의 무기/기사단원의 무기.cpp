#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> damage(number+1, 0);
    for(int i=1; i<=number; ++i){
        for(int j=1; j*j<=i; ++j){
            if(j!=1){
                if(j*j == i)
                    damage[i]++;
                else if(i%j==0)
                    damage[i]+=2;
            }
            else{
                if(i==1)
                    damage[i]++;
                else
                    damage[i]+=2;
            }
        }
        if(damage[i]>limit)
            damage[i] = power;
    }

    for(int i=1; i<=number; ++i){
        answer+=damage[i];
    }
    return answer;
}