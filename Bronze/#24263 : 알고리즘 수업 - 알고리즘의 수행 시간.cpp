/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        sum <- sum + A[i]; # Code1
    return sum;
}
첫째 줄에 Code1 의 수행 횟수를 출력한다.

둘째 줄에 알고리즘의 수행 시간이 상수 시간이 소요되면 0, n에 비례하면 1, n2에 비례하면 2, n3에 비례하면 3, n3보다 큰 시간에 비례하면 4를 출력한다.

Code1은 for문에 의해 n번 수행. 시간복잡도는 O(n)이므로 n, 1 출력
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;	cin >> n;
	cout << n  << '\n' << 1;
	return 0;
}