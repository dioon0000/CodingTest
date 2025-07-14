#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck;
    queue<int> bridge;
    queue<int> timer;
    int totalWeight = 0;

    for(int weights : truck_weights)
        truck.push(weights);

    bridge.push(truck.front());
    totalWeight+=truck.front();
    truck.pop();
    timer.push(1+bridge_length);
    answer++;

    while(!bridge.empty()){
        if(!bridge.empty())
            answer++;

        if(timer.front() == answer){
            totalWeight-=bridge.front();
            bridge.pop();
            timer.pop();
        }

        if(bridge.size()<=bridge_length && !truck.empty()) {
            if(truck.front()+totalWeight <= weight) {
                bridge.push(truck.front());
                totalWeight+=truck.front();
                truck.pop();
                timer.push(answer+bridge_length);
            }
        }
    }
    cout << answer;
    return answer;
}

int main(){
    solution(10,100,{50,30,20,10,10,10,10,10,10});
    return 0;
}