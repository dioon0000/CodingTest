#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isPrime(int n) {
    if(n < 2)
        return false;

    for(int i=2; i*i<=n; ++i) {
        if(n%i==0)
            return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> Piece;

    sort(numbers.begin(), numbers.end());

    do {
        string str;
        for(int i=0; i<numbers.size(); ++i) {
            str+=numbers[i];

            if(isPrime(stoi(str)))
                Piece.insert(stoi(str));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    answer = Piece.size();
    cout << answer;
    return answer;
}