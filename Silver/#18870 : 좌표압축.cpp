#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
  //원본 벡터
	vector<int> v(n); 
	// 입력
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
  // 원본 벡터를 복사하여 중복 된 수를 제거하고 정렬을 시행 할 벡터.
	vector<int> cv(v);
  //오름차순 정렬
	sort(cv.begin(), cv.end()); 
	// 중복 제거
	cv.erase(unique(cv.begin(), cv.end()), cv.end());
	for (int i = 0; i < n; i++)
	{
		// i번째 요소값의 위치 it
		auto it = lower_bound(cv.begin(), cv.end(), v[i]);
		// it에서 cv벡터의 시작 주소값을 빼준 값이 답
		cout << it - cv.begin() << ' ';
	}

	return 0;
}