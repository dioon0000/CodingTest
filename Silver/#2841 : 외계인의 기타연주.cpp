#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, dump, cnt = 0;
	stack<int> s[7];

	cin >> n >> dump;
	for (int i = 0; i < n; ++i) {
		int sn, fret;
		cin >> sn >> fret;

		if (s[sn].empty()) {
			s[sn].push(fret);
			cnt++;
		}
		else {
			if (s[sn].top() > fret) {
				while (s[sn].top() > fret) {
					s[sn].pop();
					cnt++;
					if (s[sn].empty()) {
						s[sn].push(fret);
						cnt++;
						break;
					}
				}
				if (s[sn].top() != fret) {
					s[sn].push(fret);
					cnt++;
				}
			}
			else if (s[sn].top() < fret) {
				s[sn].push(fret);
				cnt++;
			}
		}

	}
	cout << cnt;
	return 0;
}