#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  long long cnt=0;
  queue<int> q[21];
  
  cin >> n >> k;
  for(int i=0; i<n; ++i){
    string str;
    cin >> str;

    int len = str.length();

    while (!q[len].empty() && i-q[len].front() > k) {
			q[len].pop();
		}
		cnt += q[len].size();
		q[len].push(i);
  }

  cout << cnt;
  return 0;
}
