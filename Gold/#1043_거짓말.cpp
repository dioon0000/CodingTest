//https://www.acmicpc.net/problem/1043
//Union Find Solved
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parent[51];
vector<int> know;
vector<vector<int>> party(50);

int Find(int x){
    if(parent[x] == x)
        return x;

    return x = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    parent[x] = y;
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i)
        parent[i] = i;

    int tmp;
    while(k--){
        cin >> tmp;
        know.push_back(tmp);
    }
    
    int p, pre, num;
    for(int i=0; i<m; ++i){
        cin >> p;
        for(int j=0; j<p; ++j){
            if(j==0)
                cin >> num;
            else{
                pre = num;
                cin >> num;
                Union(pre, num);
            }
            party[i].push_back(num);
        }
    }
}
int answer(){
    int ans = m;
    //N<=50의 자연수이므로 최악의 경우 O(N^3)일 때, 2초 이내 해결가능
    for(const auto& list : party){ //vector<vector<int>> party : 이차원 벡터이므로 const auto& list는 이차원 벡터 속 각 벡터를 의미? => 개념 찾아 정리
        bool flag = false;
        for(const auto& people : list){
            for(const auto& know_people : know){
              //파티의 참석한 people과 진실을 알고있는 know_people의 부모 노드를 조사하여 같다면 해당 파티에서는 거짓말 불가능
                if(Find(people) == Find(know_people)){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans--;
                break;
            }
        }
    }

    return ans;
}

int main(){
    input();

    cout << answer() << '\n';
    return 0;
}
