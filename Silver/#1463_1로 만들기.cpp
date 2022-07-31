//https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];

int main() {
    
    cin >> n;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i <= n; i++){
        arr[i] = arr[i-1] + 1;
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i/3] + 1);
        } if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
    }
    cout << arr[n] << "\n";
    return 0;
}
