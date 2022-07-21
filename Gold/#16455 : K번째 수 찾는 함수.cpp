//https://www.acmicpc.net/problem/16455
#include <algorithm>
#include <vector>
using namespace std;

int kth(vector<int>& a, int k) {
	nth_element(a.begin(), a.begin() + k-1, a.end()); //algorithm 헤더파일에 정의되는 함수 nth_element(시작주소, nth값, 끝주소) : nth값까지 정렬하는 함수
  // O(N)
	return a[k - 1];
}
