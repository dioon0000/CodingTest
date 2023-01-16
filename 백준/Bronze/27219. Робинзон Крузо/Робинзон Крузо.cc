#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n;
    
    m = n/5;
    d = n%5;
    for(int i=0; i<m; ++i)
        cout << 'V';
    for(int i=0; i<d; ++i)
        cout << 'I';
    return 0;
}