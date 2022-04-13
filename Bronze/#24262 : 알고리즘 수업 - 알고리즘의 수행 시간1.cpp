/*
MenOfPassion(A[], n) {
    i = ⌊n / 2⌋;
    return A[i]; # Code1
}

첫째 줄에 Code1의 수행 횟수를 출력한다.

둘째 줄에 알고리즘의 수행 시간이 상수 시간이 소요되면 0, n에 비례하면 1, n2에 비례하면 2, n3에 비례하면 3, n3보다 큰 시간에 비례하면 4를 출력한다.

Code1은 n이 몇번 와도 1번만 수행. 시간복잡도는 O(1)이므로 1, 0출력
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    cout << 1 << '\n' << 0;
}