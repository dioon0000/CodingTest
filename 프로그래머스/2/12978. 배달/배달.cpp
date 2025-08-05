#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <numeric>
using namespace std;

const int INF = numeric_limits<int>::max();

// 인접 리스트 first: 목적지 , second: 가중치
vector<vector<pair<int, int>>> graph;
// 최단 거리 배열
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while(!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(dist[curr] < cost) continue;

        for(const auto& edge : graph[curr]) {
            int next = edge.first;
            int next_cost = edge.second;

            if(dist[next] > dist[curr] + next_cost) {
                dist[next] = dist[curr] + next_cost;
                pq.push({ dist[next], next });
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    graph.resize(N+1);
    dist.assign(N+1, INF);

    for(int i=0; i<road.size(); ++i) {
        int from = road[i][0];
        int to = road[i][1];
        int cost = road[i][2];

        graph[from].push_back({ to, cost });
        graph[to].push_back({ from, cost });
    }

    dijkstra(1);

    for(int i=1; i<N+1; ++i) {
        if(dist[i] <= K)
            answer++;
    }
    return answer;
}