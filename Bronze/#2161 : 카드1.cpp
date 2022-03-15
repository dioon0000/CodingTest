#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;
	int n, tmp;

	cin >> n;
	for (int i = 1; i <= n; ++i) 
		q.push(i);

	while (q.size() > 1) {
		cout << q.front() << ' ';	q.pop();
		tmp = q.front();	q.pop();
		q.push(tmp);
	}
	
	cout << q.front();
	return 0;
}