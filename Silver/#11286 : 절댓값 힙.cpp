#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> greater_pq;
	priority_queue<int, vector<int>, less<int>> less_pq;
	int t;	cin >> t;

	while (t--) {
		int x;	cin >> x;

		if (x == 0) {
			if (greater_pq.empty() && less_pq.empty())
				cout << 0 << '\n';
			else if (greater_pq.empty()) {
				cout << less_pq.top() << '\n';	less_pq.pop();
			}
			else if (less_pq.empty()) {
				cout << greater_pq.top() << '\n';	greater_pq.pop();
			}
			else {
				if (greater_pq.top() == -less_pq.top()) {
					cout << less_pq.top() << '\n';	less_pq.pop();
				}
				else if (greater_pq.top() > -less_pq.top()) {
					cout << less_pq.top() << '\n';	less_pq.pop();
				}
				else if (greater_pq.top() < -less_pq.top()) {
					cout << greater_pq.top() << '\n'; greater_pq.pop();
				}
			}
		}
		else if (x > 0)
			greater_pq.push(x);
		else if (x < 0)
			less_pq.push(x);
	}
	return 0;
}