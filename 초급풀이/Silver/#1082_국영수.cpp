#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	string name;
	int k, e, m;
};

bool compare(Student a, Student b) {
  //국어, 영어, 수학 모두 수가 같을 경우 이름을 기준으로 오름차순 정렬
	if (a.k == b.k && a.e == b.e && a.m == b.m)
		return a.name < b.name;
  //국어, 영어의 수가 같을 경우 수학을 기준으로 내림차순 정렬
	if (a.k == b.k && a.e == b.e)
		return a.m > b.m;
  //국어의 수가 같을 경우 영어를 기준으로 오름차순 정렬
	if (a.k == b.k)
		return a.e < b.e;
	//모두 만족하지 않을 때 국어를 기준으로 내림차순 정렬
	return a.k > b.k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Student> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].name >> v[i].k >> v[i].e >> v[i].m;

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; ++i)
		cout << v[i].name << '\n';
	return 0;
}
